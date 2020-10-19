#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayAccount^>^ P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayAccount()
{
	int total = 0;
	ConGatewayAccount* result = _manager->Manager->CfgRequestGatewayAccount(&total);
	IList<GatewayAccount^>^ configurations = gcnew List<GatewayAccount^>(total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayMarkup^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayMarkup()
{
	int total = 0;
	ConGatewayMarkup* result = _manager->Manager->CfgRequestGatewayMarkup(&total);
	IList<GatewayMarkup^>^ configurations = gcnew List<GatewayMarkup^>(total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}

IList<P23::MetaTrader4::Manager::Contracts::Configuration::GatewayRule^>^  P23::MetaTrader4::Manager::ClrWrapper::CfgRequestGatewayRule()
{
	int total = 0;
	ConGatewayRule* result = _manager->Manager->CfgRequestGatewayRule(&total);
	IList<GatewayRule^>^ configurations = gcnew List<GatewayRule^>(total);
	for (int i = 0; i < total; i++)
		configurations->Add(Convert(&result[i]));

	_manager->Manager->MemFree(result);

	return configurations;
}