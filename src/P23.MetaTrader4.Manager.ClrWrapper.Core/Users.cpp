#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UsersRequest()
{
	int total = 0;
	UserRecord* users = _manager->Manager->UsersRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));

	_manager->Manager->MemFree(users);

	return output;
}

IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::UserRecordsRequest(IList<int>^ logins)
{
	int total = logins->Count;
	int* l = new int[total];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];

	UserRecord* users = _manager->Manager->UserRecordsRequest(l, &total);
	IList<P23::MetaTrader4::Manager::Contracts::UserRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::UserRecord^>(total);

	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));

	_manager->Manager->MemFree(users);
	delete[] l;

	return output;
}

int P23::MetaTrader4::Manager::ClrWrapper::UserRecordNew(P23::MetaTrader4::Manager::Contracts::UserRecord^ user)
{
	UserRecord* userRecord = Convert(user);
	int result = _manager->Manager->UserRecordNew(userRecord);
	if (result == 0)
		user->Login = userRecord->login;

	delete userRecord;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::UserRecordUpdate(P23::MetaTrader4::Manager::Contracts::UserRecord^ user)
{
	UserRecord* userRecord = Convert(user);

	int result = _manager->Manager->UserRecordUpdate(userRecord);

	delete userRecord;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::UsersGroupOp(P23::MetaTrader4::Manager::Contracts::GroupCommandInfo^ info, IList<int>^ logins)
{
	GroupCommandInfo* gci = Convert(info);
	int* l = new int[logins->Count];
	for (int i = 0; i < logins->Count; i++)
		l[i] = logins[i];
	
	int result = _manager->Manager->UsersGroupOp(gci, l);
	
	delete gci;
	delete[] l;
	
	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::UserPasswordCheck(int login, String^ password)
{
	char* p = Convert(password);

	int result = _manager->Manager->UserPasswordCheck(login, p);

	Marshal::FreeHGlobal(IntPtr(p));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::UserPasswordSet(int login, String^ password, int changeInvestor, int cleanPubKey)
{
	char* p = Convert(password);

	int result = _manager->Manager->UserPasswordSet(login, p, changeInvestor, cleanPubKey);

	Marshal::FreeHGlobal(IntPtr(p));

	return result;
}

IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ P23::MetaTrader4::Manager::ClrWrapper::OnlineRequest()
{
	int total = 0;
	OnlineRecord* users = _manager->Manager->OnlineRequest(&total);
	IList<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>^ output = gcnew List<P23::MetaTrader4::Manager::Contracts::OnlineRecord^>(total);
	for (int i = 0; i < total; i++)
		output->Add(Convert(&users[i]));

	_manager->Manager->MemFree(users);

	return output;
}
