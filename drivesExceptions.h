#pragma once

#include <string>
#include <Windows.h>
#include <exception>
#include <cstdlib>
#include <stdlib.h>
#include <wchar.h>

#ifdef WINDRIVES_EXPORTS
#define WINDRIVES_API __declspec(dllexport)
#else
#define WINDRIVES_API __declspec(dllimport)
#endif // WINDRIVES_DLL


class WINDRIVES_API DriveException{
public:
	explicit DriveException(const DWORD error_code, const wchar_t* error_description) noexcept :
		error_code{ error_code }, error_description { error_description } {};

	DriveException(const DriveException& other) noexcept :
		error_code{other.error_code}, error_description{other.error_description}
	{};

	DriveException(DriveException&& other) noexcept :
		error_code{ other.error_code }, error_description{ other.error_description }
	{
		other.error_code = NULL;
		other.error_description = nullptr;
	};

	DriveException& operator=(const DriveException& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		this->error_description = other.error_description;
		return *this;
	};
	DriveException& operator=(DriveException&& other) noexcept {
		if (this == &other) {
			return *this;
		};
		this->error_code = other.error_code;
		this->error_description = other.error_description;
		other.error_code = NULL;
		other.error_description = nullptr;;
		return *this;
	};

	~DriveException() noexcept {
		error_description = nullptr;
	};

	const wchar_t* ErrorText() const {
		wchar_t code[60];
		const wchar_t* separator{ L": " };
		_ultow_s( static_cast<unsigned long>(error_code), code, 20, 10);
		wcscat_s(code, separator);
		wcscat_s(code, error_description);
		return code;
	};

private:
	DWORD error_code;
	const wchar_t* error_description{ nullptr };
};
