#ifndef UTILITYTOOLH
#define UTILITYTOOLH


#include <sstream>


class UtilityTool
{
public:       // User declarations

	static std::string int2stdstring(int inInt){

		std::stringstream ss;
		ss << inInt;

		return ss.str();
	}


	static std::string float2stdstring(float inFloat){

		std::stringstream ss;
		ss << inFloat;

		return ss.str();
	}
	
	static std::string net2StdString ( System::String^ s )
	{   
		std::string os;
		using namespace System::Runtime::InteropServices;   
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();   
		os = chars;   
		Marshal::FreeHGlobal(System::IntPtr((void*)chars));

		return os;
	}

	static System::String^ std2NetString(const std::string& s)
	{
		return gcnew System::String(s.c_str());
	}
};

#endif