#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::ChartRequest(P23::MetaTrader4::Manager::Contracts::ChartInfo^ chart, [System::Runtime::InteropServices::Out]UInt32% timesign)
{
	int total = 0;
	__time32_t time;
	ChartInfo* chartInfo = Convert(chart);
	RateInfo* result = _manager->Manager->ChartRequest(chartInfo, &time, &total);
	IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::RateInfo^>(total);
	timesign = time;

	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);
	delete chartInfo;

	return output;	
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartAdd(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	char* s = Convert(symbol);

	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);

	int result = _manager->Manager->ChartAdd(s, period, unmanagedRates, &total);

	Marshal::FreeHGlobal(IntPtr(s));
	delete[] unmanagedRates;

	return result;	
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartUpdate(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	char* s = Convert(symbol);

	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);

	int result = _manager->Manager->ChartUpdate(s, period, unmanagedRates, &total);

	Marshal::FreeHGlobal(IntPtr(s));
	delete[] unmanagedRates;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::ChartDelete(String^ symbol, int period, IList<P23::MetaTrader4::Manager::Contracts::RateInfo^>^ rates)
{
	int total = rates->Count;
	RateInfo* unmanagedRates = new RateInfo[total];
	char* s = Convert(symbol);

	for (int i = 0; i < total; i++)
		unmanagedRates[i] = *Convert(rates[i]);
	
	int result = _manager->Manager->ChartDelete(s, period, unmanagedRates, &total);

	Marshal::FreeHGlobal(IntPtr(s));
	delete[] unmanagedRates;

	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::TicksRequest(P23::MetaTrader4::Manager::Contracts::TickRequest^ request)
{
	int total = 0;
	TickRequest* tickRequest = Convert(request);

	TickRecord* result = _manager->Manager->TicksRequest(tickRequest, &total);
	IList<P23::MetaTrader4::Manager::Contracts::TickRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TickRecord^>(total);

	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);
	delete tickRequest;

	return output;
}