#pragma once

#include "pch.h"
#include <Windows.h>
#include <string>


#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else 
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_EXPORTS


class WINDRIVES_API DriveException {
public:
	explicit DriveException(const DWORD error_code) noexcept
		: error_code{ error_code } {};

	DriveException(const DriveException& other) noexcept :
		error_code{ other.error_code } {};

	DriveException(DriveException&& other) noexcept :
		error_code{ other.error_code } {
		other.error_code = NULL;
	};

	DriveException& operator=(const DriveException& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		return *this;
	};
	DriveException& operator=(DriveException&& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		return *this;
	};

	~DriveException() noexcept {};

protected:
	DWORD error_code{ NULL };
};

class WINDRIVES_API BadDriveSearch : public DriveException {
public:
	explicit BadDriveSearch(const DWORD error_code, const wchar_t* error_description) noexcept : 
		DriveException{ error_code }, error_description { std::wstring{ error_description } } {};
	explicit BadDriveSearch(const DWORD error_code, const char* error_description) noexcept:
		DriveException{ error_code }, error_description{ str2wstr(error_description) }{};

	BadDriveSearch(const BadDriveSearch& other) noexcept : 
		DriveException{ other.error_code }, error_description{ other.error_description }
	{};

	BadDriveSearch(BadDriveSearch&& other) noexcept :
		DriveException{ other.error_code }, error_description{ other.error_description }
	{
		other.error_code = NULL;
		other.error_description = std::wstring{ L"moved" };
	};

	BadDriveSearch& operator=(const BadDriveSearch& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		this->error_description = other.error_description;
		return *this;
	};
	BadDriveSearch& operator=(BadDriveSearch&& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		this->error_description = other.error_description;
		other.error_code = NULL;
		other.error_description = std::wstring{ L"moved" };
		return *this;
	};

	~BadDriveSearch() noexcept {};
private:
	std::wstring error_description{ NULL };

	std::wstring str2wstr(const std::string& string) const noexcept {
		return std::wstring{ string.begin(), string.end() };
	};

	std::wstring str2wstr(const char* chars) const noexcept {
		std::string string{ chars };
		return std::wstring{ string.begin(), string.end() };
	};
};
