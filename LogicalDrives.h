#pragma once
#include <Windows.h>
#include <cctype>
#include <list>
#include <map>
#include <iostream>

#include "Volume.h"

class LogicalDrives
{
public:
	LogicalDrives() noexcept;
	~LogicalDrives() noexcept;

	LogicalDrives(const LogicalDrives&) = delete;
	LogicalDrives(LogicalDrives&&) = delete;

	std::list<const Volume> DRIVES;

	void printInfo();

private:
	void findDrives();

	const wchar_t* detectDriveType(const UINT);
	std::map<const UINT, const wchar_t*> types{
		{0, L"DRIVE_UNKNOWN"},
		{1, L"NO_ROOT_DIR"},
		{2, L"REMOVABLE"},
		{3, L"FIXED"},
		{4, L"REMOTE"},
		{5, L"CDROM"},
		{6, L"RAMDISK"}
	};
};

