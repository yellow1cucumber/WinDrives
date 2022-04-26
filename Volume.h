#pragma once
#include <Windows.h>
#include <string>

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
	Volume(const Volume&) noexcept;
	Volume(Volume&&) noexcept;

	Volume& operator=(const Volume&) noexcept;
	Volume& operator=(Volume&&) noexcept;

	bool operator==(const Volume&) noexcept;

	~Volume() noexcept {};

	std::wstring rootPath() const noexcept;
	std::wstring volumeName() const noexcept;
	uint64_t serialNumber() const noexcept;
	uint64_t maxComponentLength() const noexcept;
	uint64_t fileSystemFlags() const noexcept;
	std::wstring fileSystemName() const noexcept;

private:
	std::wstring root_path;
	std::wstring volume_name;
	uint64_t serial_number;
	uint64_t max_component_len;
	uint64_t file_system_flags;
	std::wstring file_system_name;
};

