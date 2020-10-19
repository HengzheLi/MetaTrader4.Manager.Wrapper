using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Tests.Helpers;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ExtendedPumpingTests
    {
        [TestMethod]
        public void PumpingSwitchEx_Invoked_PumpingStartedRised()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                bool pumpingStarted = false;
                mt.PumpingStarted += (sender, args) =>
                {
                    pumpingStarted = true;
                    autoResetEvent.Set();
                };
                
                //Act
                mt.PumpingSwitchEx(PumpingMode.Default);

                //Assert
                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStarted);
            }
        }
    }
}
