#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

Common^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestCommon()
{
	ConCommon configuration;
	int result = _manager->Manager->CfgRequestCommon(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

Time^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestTime()
{
	ConTime configuration;
	int result = _manager->Manager->CfgRequestTime(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

Backup^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestBackup()
{
	ConBackup configuration;
	int result = _manager->Manager->CfgRequestBackup(&configuration);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}
	return Convert(&configuration);
}

IList<SymbolGroup^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSymbolGroup()
{
	ConSymbolGroup configurations[MAX_SEC_GROUP];
	int result = _manager->Manager->CfgRequestSymbolGroup(configurations);
	if (result != RET_OK)
	{
		MetaTrader4::Manager::Contracts::MetaTraderException^ exception = gcnew MetaTrader4::Manager::Contracts::MetaTraderException();
		exception->ErrorCode = result;
		throw exception;
	}

	IList<SymbolGroup^>^ output = gcnew List<SymbolGroup^>(MAX_SEC_GROUP);
	for (int i = 0; i < MAX_SEC_GROUP; i++) 	
		output->Add(Convert(&configurations[i]));
	
	return output;
}

IList<Access^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestAccess()
{
	int total = 0;
	ConAccess* result = _manager->Manager->CfgRequestAccess(&total);
	IList<Access^>^ configurations = gcnew List<Access^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	
	_manager->Manager->MemFree(result);

	return configurations;
}

IList<DataServer^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestDataServer()
{
	int total = 0;
	ConDataServer* result = _manager->Manager->CfgRequestDataServer(&total);
	IList<DataServer^>^ configurations = gcnew List<DataServer^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<Holiday^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestHoliday()
{
	int total = 0;
	ConHoliday* result = _manager->Manager->CfgRequestHoliday(&total);
	IList<Holiday^>^ configurations = gcnew List<Holiday^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<Symbol^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSymbol()
{
	int total = 0;
	ConSymbol* result = _manager->Manager->CfgRequestSymbol(&total);
	IList<Symbol^>^ configurations = gcnew List<Symbol^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));
	
	_manager->Manager->MemFree(result);

	return configurations;
}

IList<Group^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGroup()
{
	int total = 0;
	ConGroup* result = _manager->Manager->CfgRequestGroup(&total);
	IList<Group^>^ configurations = gcnew List<Group^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^     P23::MetaTrader4::Manager::ClrWrapper::CfgRequestManager()
{
	int total = 0;
	ConManager* result = _manager->Manager->CfgRequestManager(&total);
	IList<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>^ configurations = gcnew List<P23::MetaTrader4::Manager::Contracts::Configuration::Manager^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<Feeder^>^      P23::MetaTrader4::Manager::ClrWrapper::CfgRequestFeeder()
{
	int total = 0;
	ConFeeder* result = _manager->Manager->CfgRequestFeeder(&total);
	IList<Feeder^>^ configurations = gcnew List<Feeder^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<LiveUpdate^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestLiveUpdate()
{
	int total = 0;
	ConLiveUpdate* result = _manager->Manager->CfgRequestLiveUpdate(&total);
	IList<LiveUpdate^>^ configurations = gcnew List<LiveUpdate^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<Synchronization^>^        P23::MetaTrader4::Manager::ClrWrapper::CfgRequestSync()
{
	int total = 0;
	ConSync* result = _manager->Manager->CfgRequestSync(&total);
	IList<Synchronization^>^ configurations = gcnew List<Synchronization^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<PluginWithParameters^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestPlugin()
{
	int total = 0;
	ConPluginParam* result = _manager->Manager->CfgRequestPlugin(&total);
	IList<PluginWithParameters^>^ configurations = gcnew List<PluginWithParameters^>(total);

	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}