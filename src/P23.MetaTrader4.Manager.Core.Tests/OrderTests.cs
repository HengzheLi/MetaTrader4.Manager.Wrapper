using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;
using System.Collections.Generic;
using System.Configuration;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class OrderTests
    {
        [TestMethod]
        public void TradeTransaction_ValidParametersPassed_TransactionExecuted()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var tti = new TradeTransInfo
                {
                    Cmd = TradeCommand.Balance,
                    OrderBy = 1000,
                    Comment = "Test deposit",
                    Price = 1,
                    Type = TradeTransactionType.BrBalance
                };

                //Act
                var result = mt.TradeTransaction(tti);

                //Assert
                Assert.AreEqual(0, result);
                Assert.IsTrue(tti.Order > 1000);
            }
        }

        [TestMethod]
        public void TradeTransaction_ParametersToOpenTradeProvided_TradeOpened()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var tti = new TradeTransInfo
                {
                    Cmd = TradeCommand.Balance,
                    OrderBy = 1000,
                    Comment = "Test deposit",
                    Price = 1,
                    Type = TradeTransactionType.BrBalance
                };

                //Act
                var result = mt.TradeTransaction(tti);

                //Assert
                Assert.AreEqual(0, result);
                Assert.IsTrue(tti.Order > 1000);
            }
        }

        [TestMethod]
        public void OpenAndCloseOrder()
        {
            var ticketList = new List<int>();
            var testAccount = 1111;// int.Parse(ConfigurationManager.AppSettings["testaccount"]);
            using (var mt = TestHelpers.CreateWrapper())
            {
                for (int i = 0; i < 10; i++)
                {
                    //arrange
                    var tti = new TradeTransInfo();
                    tti.Cmd = TradeCommand.Buy;
                    tti.Type = TradeTransactionType.BrOrderOpen;
                    tti.Symbol = "EURUSD";
                    tti.Comment = "unit test";
                    tti.OrderBy = testAccount;
                    tti.Price = 1.16033;
                    tti.Volume = 10;

                    //act
                    var result = mt.TradeTransaction(tti);

                    //assert
                    Assert.AreEqual(0, result);
                    Assert.IsTrue(tti.Order > 0);
                    ticketList.Add(tti.Order);
                }

                foreach (var item in ticketList)
                {
                    //arrange
                    var tti = new TradeTransInfo();
                    tti.Cmd = TradeCommand.Buy;
                    tti.Type = TradeTransactionType.BrOrderClose;
                    tti.Symbol = "EURUSD";
                    tti.Comment = "unit test";
                    tti.OrderBy = testAccount;
                    tti.Price = 1.16033;
                    tti.Volume = 10;
                    tti.Order = item;

                    //act
                    var result = mt.TradeTransaction(tti);

                    //assert
                    Assert.AreEqual(0, result,$"close order {tti.Order} error");
                }
            }
        }
    }
}
