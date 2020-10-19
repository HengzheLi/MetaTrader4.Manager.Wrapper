#include "stdafx.h"
#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayAccount(GatewayAccount^ configuration)
{
	ConGatewayAccount* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateGatewayAccount(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayMarkup(GatewayMarkup^ configuration)
{
	ConGatewayMarkup* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateGatewayMarkup(cfg);

	delete cfg;

	return result;
}

int P23::MetaTrader4::Manager::ClrWrapper::CfgUpdateGatewayRule(GatewayRule^ configuration)
{
	ConGatewayRule* cfg = Convert(configuration);

	int result = _manager->Manager->CfgUpdateGatewayRule(cfg);

	delete cfg;

	return result;
}