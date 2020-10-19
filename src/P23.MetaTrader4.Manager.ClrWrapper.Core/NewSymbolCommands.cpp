#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::SymbolChange(P23::MetaTrader4::Manager::Contracts::SymbolProperties^ symbolProperties)
{
	SymbolProperties* props = Convert(symbolProperties);

	int result = _manager->Manager->SymbolChange(props);
	
	delete props;

	return result;
}