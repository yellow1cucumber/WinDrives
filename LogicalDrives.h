#pragma once
#include <Windows.h>
#include <iostream>

#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else 
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_EXPORTS

class WINDRIVES_API LogicalDrives
{
public:
	LogicalDrives() noexcept;
	~LogicalDrives() noexcept;

	LogicalDrives(const LogicalDrives&) = delete;
	LogicalDrives(LogicalDrives&&) = delete;

private:
	//std::list<>

	void findDrives();
};

