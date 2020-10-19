#include "stdafx.h"

#include "P23.MetaTrader4.Manager.ClrWrapper.h"

void P23::MetaTrader4::Manager::ClrWrapper::LogsOut(int code, System::String^ source, System::String^ msg)
{
	if (System::String::IsNullOrEmpty(source))
		throw gcnew ArgumentNullException("source");

	if (System::String::IsNullOrEmpty(msg))
		throw gcnew ArgumentNullException("msg");
	
	char* s = Convert(source);
	char* m = Convert(msg);

	_manager->Manager->LogsOut(code, s, m);

	Marshal::FreeHGlobal(IntPtr(s));
	Marshal::FreeHGlobal(IntPtr(m));
}

void P23::MetaTrader4::Manager::ClrWrapper::LogsMode(int mode)
{
	_manager->Manager->LogsMode(mode);
}