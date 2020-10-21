using System;
using System.IO;
using P23.MetaTrader4.Manager.Contracts;
using System.Configuration;
using System.Reflection;
using Microsoft.Extensions.Configuration;

namespace P23.MetaTrader4.Manager.Tests.Helpers
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
                return new ConnectionParameters {
                    Login = int.Parse(config["account"]),
                    Password = config["password"],
                    Server = config["ipaddress"]
                };
            });

        public static ClrWrapper CreateWrapper()
        {
            var directory = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            return new ClrWrapper(GetCredentials(),Path.Combine(directory,"mtmanapi.dll"));
        }

        public static ConnectionParameters GetCredentials()
        {
            return LazyParameters.Value;
        }
    }
}