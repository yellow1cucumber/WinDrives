#pragma once
#include <Windows.h>

#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else 
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_EXPORTS

class WINDRIVES_API Volume
{
public:
	explicit Volume(const wchar_t* root_path,
					const wchar_t* volume_name,
					const unsigned long int serial_number,
					const unsigned long int max_component_len,
					const unsigned long int fs_flags,
					const wchar_t* fs_name) noexcept;
};

