#pragma once

#include <Windows.h>
#include <iostream>

#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_DLL

class WINDRIVES_API Volume {
public:

	typedef unsigned long ulint;

	explicit Volume(LPWSTR root_path,
					LPWSTR volume_name,
					DWORD serial_number,
					DWORD max_component_len,
					DWORD fs_flags,
					LPWSTR fs_name,
					const wchar_t* drive_type) noexcept;

	Volume(const Volume&) noexcept;
	Volume(Volume&&) noexcept;

	Volume& operator=(const Volume&) noexcept;
	Volume& operator=(Volume&&) noexcept;

	bool operator==(const Volume&) noexcept;
	~Volume() noexcept;

// GET
	const wchar_t* rootPath() const noexcept;
	const wchar_t* volumeName() const noexcept;
	const ulint serialNumber() const noexcept;
	const ulint maxComponentLength() const noexcept;
	const ulint fileSystemFlags() const noexcept;
	const wchar_t* fileSystemName() const noexcept;
	const wchar_t* driveType() const noexcept;

	void printInfo() const noexcept;

private:
	wchar_t* root_path{ nullptr };
	wchar_t* volume_name{ nullptr };
	ulint serial_number{ NULL };
	ulint max_component_len{ NULL };
	ulint file_system_flags{ NULL };
	wchar_t* file_system_name{ nullptr };
	const wchar_t* drive_type{ nullptr };
};