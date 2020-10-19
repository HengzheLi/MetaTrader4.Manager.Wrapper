#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

int P23::MetaTrader4::Manager::ClrWrapper::LicenseCheck(System::String^ licenseName)
{
	if (System::String::IsNullOrEmpty(licenseName))
		throw gcnew ArgumentNullException("licenseName");
	
	char* ln = Convert(licenseName);

	int result = _manager->Manager->LicenseCheck(ln);

	Marshal::FreeHGlobal(IntPtr(ln));
	
	return result;
}