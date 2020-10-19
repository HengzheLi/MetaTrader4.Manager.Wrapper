#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::TradeCalcProfit(P23::MetaTrader4::Manager::Contracts::TradeRecord^ trade)
{
	TradeRecord* tradeRecord = Convert(trade);

	int result = _manager->Manager->TradeCalcProfit(tradeRecord);
	trade->Profit = tradeRecord->profit;

	delete tradeRecord;

	return result;
}