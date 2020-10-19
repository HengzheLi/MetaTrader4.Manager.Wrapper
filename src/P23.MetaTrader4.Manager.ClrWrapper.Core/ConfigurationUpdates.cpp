#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateCommon(Common^ configuration)
{
	ConCommon* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateCommon(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateAccess(Access^ configuration, int position)
{
	ConAccess* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateAccess(cfg, position);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateDataServer(DataServer^ configuration, int position)
{
	ConDataServer* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateDataServer(cfg, position);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateTime(Time^ configuration)
{
	ConTime* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateTime(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateHoliday(Holiday^ configuration, int position)
{
	ConHoliday* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateHoliday(cfg, position);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSymbol(Symbol^ configuration)
{
	ConSymbol* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateSymbol(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSymbolGroup(SymbolGroup^ configuration, int position)
{
	ConSymbolGroup* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateSymbolGroup(cfg, position);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGroup(Group^ configuration)
{
	ConGroup* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateGroup(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateManager(P23::MetaTrader4::Manager::Contracts::Configuration::Manager^ configuration)
{
	ConManager* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateManager(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateFeeder(Feeder^ configuration)
{
	ConFeeder* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateFeeder(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateBackup(Backup^ configuration)
{
	ConBackup* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateBackup(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateLiveUpdate(LiveUpdate^ configuration)
{
	ConLiveUpdate* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateLiveUpdate(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateSync(Synchronization^ configuration)
{
	ConSync* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateSync(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdatePlugin(Plugin^ configuration, IList<PluginConfigurationParameter^>^ parameters)
{
	ConPlugin* cfg = Convert(configuration);
	PluginCfg* params = new PluginCfg[parameters->Count];

	for (int i = 0; i < parameters->Count; i++)
		params[i] = *Convert(parameters[i]);

	int result = _manager->Manager->CfgUpdatePlugin(Convert(configuration), params, parameters->Count);

	delete[] params;
	delete cfg;

	return result;
}