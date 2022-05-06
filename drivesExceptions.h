#pragma once

#include <string>
#include <Windows.h>
#include <exception>
#include <cstdlib>


class DriveException {
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

class BadDriveSearch : public DriveException {
public:
	explicit BadDriveSearch(const DWORD error_code, const wchar_t* error_description) noexcept : 
		DriveException{ error_code }, error_description { error_description } {};

	BadDriveSearch(const BadDriveSearch& other) noexcept : 
		DriveException{ other.error_code }, error_description{ other.error_description }
	{};

	BadDriveSearch(BadDriveSearch&& other) noexcept :
		DriveException{ other.error_code }, error_description{ other.error_description }
	{
		other.error_code = NULL;
		other.error_description = nullptr;
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
		other.error_description = nullptr;;
		return *this;
	};

	~BadDriveSearch() noexcept {
		delete error_description;
	};

private:
	const wchar_t* error_description;
};
