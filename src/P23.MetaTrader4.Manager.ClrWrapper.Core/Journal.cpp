#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::ServerLog^>^ P23::MetaTrader4::Manager::ClrWrapper::JournalRequest(int mode, UInt32 from, UInt32 to, String^ filter)
{
	int total = 0;
	char* f = Convert(filter);
	ServerLog* logs = _manager->Manager->JournalRequest(mode, from, to, f, &total);

	IList<P23::MetaTrader4::Manager::Contracts::ServerLog^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::ServerLog^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&logs[i]));

	_manager->Manager->MemFree(logs);
	Marshal::FreeHGlobal(IntPtr(f));

	return output;
}