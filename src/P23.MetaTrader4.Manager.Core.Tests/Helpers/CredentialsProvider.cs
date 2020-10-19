using System;
using System.IO;
using P23.MetaTrader4.Manager.Contracts;
using System.Configuration;
using System.Reflection;

namespace P23.MetaTrader4.Manager.Tests.Helpers
{
    internal static class TestHelpers
    {
        private static readonly Lazy<ConnectionParameters> LazyParameters =
            new Lazy<ConnectionParameters>(() =>
            {
                return new ConnectionParameters {
                    Login = int.Parse(ConfigurationManager.AppSettings["account"]),
                    Password = ConfigurationManager.AppSettings["password"],
                    Server = ConfigurationManager.AppSettings["ipaddress"]
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