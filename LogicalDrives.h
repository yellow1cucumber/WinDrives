#pragma once
#include <Windows.h>
#include <list>
#include <map>
#include <iostream>

#include "Volume.h"

#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_DLL

class WINDRIVES_API LogicalDrives
{
public:
	LogicalDrives() noexcept;
	~LogicalDrives() noexcept;

	LogicalDrives(const LogicalDrives&) = delete;
	LogicalDrives(LogicalDrives&&) = delete;

	std::list<Volume> DRIVES;

	void printInfo();

private:
	void findDrives();

	const wchar_t* detectDriveType(const UINT);
	std::map<UINT, std::wstring> types{
		{0, std::wstring{L"DRIVE_UNKNOWN"}},
		{1, std::wstring{L"NO_ROOT_DIR"}},
		{2, std::wstring{L"REMOVABLE"}},
		{3, std::wstring{L"FIXED"}},
		{4, std::wstring{L"REMOTE"}},
		{5, std::wstring{L"CDROM"}},
		{6, std::wstring{L"RAMDISK"}}
	};
};

