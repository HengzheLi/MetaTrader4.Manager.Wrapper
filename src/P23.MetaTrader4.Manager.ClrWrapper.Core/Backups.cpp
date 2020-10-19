#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupInfoUsers(int mode)
{
	int total = 0;
	BackupInfo* result = _manager->Manager->BackupInfoUsers(mode, &total);
	IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::BackupInfo^>(total);
	for (int i = 0; i < total; i++)	
		output->Add(Convert(&result[i]));
	
	_manager->Manager->MemFree(result);

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^  P23::MetaTrader4::Manager::ClrWrapper::BackupInfoOrders(int mode)
{
	int total = 0;
	BackupInfo* result = _manager->Manager->BackupInfoOrders(mode, &total);
	IList<P23::MetaTrader4::Manager::Contracts::BackupInfo^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::BackupInfo^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^  P23::MetaTrader4::Manager::ClrWrapper::BackupRequestUsers(String^ file, String^ request)
{
	int total = 0;
	
	char* f = Convert(file);
	char* r = Convert(request);
	if (f == NULL || r == NULL)
		throw gcnew ArgumentException("File and request mandatory parameters");
	
	UserRecord* result = _manager->Manager->BackupRequestUsers(f, r, &total);
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);
	Marshal::FreeHGlobal(IntPtr(f));
	Marshal::FreeHGlobal(IntPtr(r));

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupRequestOrders(String^ file, String^ request)
{
	int total = 0;

	char* f = Convert(file);
	char* r = Convert(request);
	if (f == NULL || r == NULL)
		throw gcnew ArgumentException("File and request mandatory parameters");

	TradeRecord* result = _manager->Manager->BackupRequestOrders(f, r, &total);
	IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRecord^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);
	Marshal::FreeHGlobal(IntPtr(f));
	Marshal::FreeHGlobal(IntPtr(r));

	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::BackupRestoreUsers(IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ users)
{
	int total = users->Count;

	UserRecord* u = new UserRecord[total];
	for (int i = 0; i < total; i++)
		u[i] = *Convert(users[i]);

	int result = _manager->Manager->BackupRestoreUsers(u, total);
	
	delete[] u;

	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>^ P23::MetaTrader4::Manager::ClrWrapper::BackupRestoreOrders(IList<P23::MetaTrader4::Manager::Contracts::TradeRecord^>^ trades)
{
	int total = trades->Count;

	TradeRecord* t = new TradeRecord[total];
	for (int i = 0; i < total; i++)
		t[i] = *Convert(trades[i]);

	TradeRestoreResult* result = _manager->Manager->BackupRestoreOrders(t, &total);

	IList<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::TradeRestoreResult^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);
	delete[] t;

	return output;
}