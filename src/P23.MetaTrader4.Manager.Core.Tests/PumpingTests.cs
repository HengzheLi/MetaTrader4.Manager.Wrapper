using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class PumpingTests
    {
        [TestMethod]
        public void SymbolsGroupsGet_Invoked_SymbolGroupsReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                bool pumpingStarted = false;
                
                mt.PumpingSwitch(i =>
                {
                    if ((PumpingNotificationCodes) i == PumpingNotificationCodes.Start)
                    {
                        autoResetEvent.Set();
                        pumpingStarted = true;
                    }
                });
                
                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStarted, "Pumping was not started");

                //Act
                var groups = mt.SymbolsGroupsGet();

                //Assert
                Assert.IsTrue(groups.Count > 0, "No symbol groups returned");
                Assert.IsFalse(string.IsNullOrEmpty(groups[0].Name));
            }
        }

        [TestMethod]
        public void PumpingSwitch_SecondInvocationWillReassignCallback()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEventFirstPumpingStarted = new AutoResetEvent(false);
                var autoResetEventFirstPumpingStopped = new AutoResetEvent(false);
                bool pumpingStartedForFirstTime = false;
                bool pumpingStoppedForFirstTime = false;

                mt.PumpingSwitch(i =>
                {
                    if ((PumpingNotificationCodes)i == PumpingNotificationCodes.Start)
                    {
                        pumpingStartedForFirstTime = true;
                        autoResetEventFirstPumpingStarted.Set();
                    }
                    if ((PumpingNotificationCodes)i == PumpingNotificationCodes.Stop)
                    {
                        pumpingStoppedForFirstTime = true;
                        autoResetEventFirstPumpingStopped.Set();
                    }
                });

                autoResetEventFirstPumpingStarted.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStartedForFirstTime, "Pumping was not started for first time");

                //Act
                var usersRequestResult = mt.UsersRequest();
                Assert.AreEqual(0, usersRequestResult.Count);


                autoResetEventFirstPumpingStopped.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStoppedForFirstTime, "Pumping was not stopped for first time");

                var autoResetEventSecondPumpingStarted = new AutoResetEvent(false);
                bool pumpingStartedForSecondTime = false;

                var credentials = TestHelpers.GetCredentials();
                mt.Connect(credentials.Server);
                mt.Login(credentials.Login, credentials.Password);

                var pumpingSwitchResult = mt.PumpingSwitch(i =>
                {
                    if ((PumpingNotificationCodes)i == PumpingNotificationCodes.Start)
                    {
                        pumpingStartedForSecondTime = true;
                        autoResetEventSecondPumpingStarted.Set();
                    }
                });
                
                Assert.AreEqual(0, pumpingSwitchResult);

                autoResetEventSecondPumpingStarted.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStartedForSecondTime, "Pumping was not started for second time");
                var usersGetResult = mt.UsersGet();
                Assert.IsTrue(usersGetResult.Count > 0);
            }
        }

        [TestMethod]
        public void MarginLevelGet_Invoke_ValidDataReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                bool pumpingStarted = false;

                mt.PumpingSwitch(i =>
                {
                    if ((PumpingNotificationCodes)i == PumpingNotificationCodes.Start)
                    {
                        autoResetEvent.Set();
                        pumpingStarted = true;
                    }
                });

                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStarted, "Pumping was not started");

                //Act
                var result = mt.MarginLevelGet(1000, "DE-100-100-demo");

                //Assert
                Assert.IsNotNull(result);
            }
        }
    }
}