using System;
using System.IO;
using System.Reflection;
using Microsoft.Extensions.Configuration;
using P23.MetaTrader4.Manager;
using P23.MetaTrader4.Manager.Contracts;

namespace TestConsole
{
    internal static class TestHelpers
    {
        static IConfiguration config;

        static TestHelpers()
        {
            var builder = new ConfigurationBuilder();
            builder.AddJsonFile("appsettings.json");
            config = builder.Build();
        }

        private static readonly Lazy<ConnectionParameters> LazyParameters =
            new Lazy<ConnectionParameters>(() =>
            {
                return new ConnectionParameters
                {
                    Login = int.Parse(config["account"]),
                    Password = config["password"],
                    Server = config["ipaddress"]
                };
            });

        public static ClrWrapper CreateWrapper()
        {
            var directory = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            return new ClrWrapper(GetCredentials(), Path.Combine(directory, "mtmanapi.dll"));
        }

        public static ConnectionParameters GetCredentials()
        {
            return LazyParameters.Value;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            using (var mt = TestHelpers.CreateWrapper())
            {
                var users = mt.UsersRequest();
                Console.WriteLine(users.Count);
            }
            Console.ReadKey();
        }
    }
}
