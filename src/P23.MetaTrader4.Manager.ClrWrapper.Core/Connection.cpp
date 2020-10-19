#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::Connect(System::String^ server)
{
	char* cServer = Convert(server);
	if (cServer == NULL)
		throw gcnew ArgumentException("Server missing", "server");

	int result = _manager->Manager->Connect(cServer);

	Marshal::FreeHGlobal(IntPtr(cServer));
	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::Disconnect()
{
	return _manager->Manager->Disconnect();
}

int P23::MetaTrader4::Manager::ClrWrapper::IsConnected()
{
	return _manager->Manager->IsConnected();
}

int P23::MetaTrader4::Manager::ClrWrapper::Login(int login, System::String^ password)
{	
	char* cPassword = Convert(password);
	if (cPassword == NULL)
		throw gcnew ArgumentException("Password is required");

	int result = _manager->Manager->Login(login, cPassword);

	Marshal::FreeHGlobal(IntPtr(cPassword));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::LoginSecured(System::String^ keyPath)
{
	char* cKeyPath = Convert(keyPath);
	if (cKeyPath == NULL)
		throw gcnew ArgumentException("keyPath is required");

	int result = _manager->Manager->LoginSecured(cKeyPath);
	
	Marshal::FreeHGlobal(IntPtr(cKeyPath));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::KeysSend(System::String^ keyPath)
{
	char* cKeyPath = Convert(keyPath);
	if (cKeyPath == NULL)
		throw gcnew ArgumentException("keyPath is required");

	int result = _manager->Manager->KeysSend(cKeyPath);
	Marshal::FreeHGlobal(IntPtr(cKeyPath));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::Ping()
{
	return _manager->Manager->Ping();
}

int P23::MetaTrader4::Manager::ClrWrapper::PasswordChange(System::String^ password, int isInvestor)
{
	char* cPassword = Convert(password);
	if (cPassword == NULL)
		throw gcnew ArgumentException("password is required");

	int result = _manager->Manager->PasswordChange(cPassword, isInvestor);
	Marshal::FreeHGlobal(IntPtr(cPassword));

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::ManagerRights(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ manager)
{
	ConManager* m = Convert(manager);

	int result = _manager->Manager->ManagerRights(m);

	delete m;

	return result;
}