﻿using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ReportsTests
    {
        [TestMethod]
        public void ReportsRequestTest()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var logins = new List<int>{1};
                var reports = mt.ReportsRequest(new ReportGroupRequest() { From = 1434974798, Name = "test", To = 1435100000 }, logins);
                Assert.IsNotNull(reports);
            }
        }
    }
}