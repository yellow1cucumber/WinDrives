#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <cctype>


typedef unsigned long ulint;

class Volume
{
public:
	explicit Volume(const LPWSTR root_path,
					const LPWSTR volume_name,
					LPDWORD serial_number,
					LPDWORD max_component_len,
					LPDWORD fs_flags,
					const LPWSTR fs_name,
					const wchar_t* drive_type) noexcept;


	Volume(const Volume&) noexcept;
	Volume(Volume&&) noexcept;

	Volume& operator=(const Volume&) noexcept;
	Volume& operator=(Volume&&) noexcept;

	bool operator==(const Volume&) noexcept;

	~Volume() noexcept {};

	const wchar_t* rootPath() const noexcept;
	const wchar_t* volumeName() const noexcept;
	const ulint serialNumber() const noexcept;
	const ulint maxComponentLength() const noexcept;
	const ulint fileSystemFlags() const noexcept;
	const wchar_t* fileSystemName() const noexcept;
	const wchar_t* driveType() const noexcept;

	const void printInfo() const noexcept;

private:
	wchar_t* root_path;
	wchar_t* volume_name;
	ulint serial_number;
	ulint max_component_len;
	ulint file_system_flags;
	wchar_t* file_system_name;
	const wchar_t* drive_type;
};

