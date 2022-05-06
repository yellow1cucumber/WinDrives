#include "pch.h"
#include "Volume.h"

typedef unsigned long ulint;

Volume::Volume(	const LPWSTR root_path,
				const LPWSTR volume_name,
				LPDWORD serial_number,
				LPDWORD max_component_len,
				LPDWORD fs_flags,
				const LPWSTR fs_name,
				const wchar_t* drive_type) noexcept :

	root_path{root_path},
	volume_name{volume_name},
	serial_number{*serial_number},
	max_component_len{*max_component_len},
	file_system_flags{*fs_flags},
	file_system_name{fs_name},
	drive_type{drive_type}
{}

Volume::Volume(const Volume& other) noexcept :
	root_path{other.root_path},
	volume_name{other.volume_name},
	serial_number{other.serial_number},
	max_component_len{other.max_component_len},
	file_system_flags{other.file_system_flags},
	file_system_name{other.file_system_name},
	drive_type{other.drive_type}
{}

Volume::Volume(Volume&& other) noexcept :
	root_path{other.root_path},
	volume_name{other.volume_name},
	serial_number{other.serial_number},
	max_component_len{other.max_component_len},
	file_system_flags{other.file_system_flags},
	file_system_name{other.file_system_name},
	drive_type{other.drive_type}
{
	other.root_path = nullptr;
	other.volume_name = nullptr;
	other.serial_number = NULL;
	other.max_component_len = NULL;
	other.file_system_flags = NULL;
	other.file_system_name = nullptr;
	other.drive_type = NULL;
}

Volume& Volume::operator=(const Volume& other) noexcept {
	if (this == &other) {
		return *this;
	};
	
	this->root_path = other.root_path;
	this->volume_name = other.volume_name;
	this->serial_number = other.serial_number;
	this->max_component_len = other.max_component_len;
	this->file_system_flags = other.file_system_flags;
	this->file_system_name = other.file_system_name;
	this->drive_type = other.drive_type;
	return *this;
}

Volume& Volume::operator=(Volume&& other) noexcept {
	if (this == &other) {
		return *this;
	};

	this->root_path = other.root_path;
	this->volume_name = other.volume_name;
	this->serial_number = other.serial_number;
	this->max_component_len = other.max_component_len;
	this->file_system_flags = other.file_system_flags;
	this->file_system_name = other.file_system_name;

	other.root_path = nullptr;
	other.volume_name = nullptr;
	other.serial_number = NULL;
	other.max_component_len = NULL;
	other.file_system_flags = NULL;
	other.file_system_name = nullptr;
	other.drive_type = NULL;

	return *this;
}

bool Volume::operator==(const Volume& other) noexcept {
	if (
			this->root_path == other.root_path &&
			this->volume_name == other.volume_name &&
			this->serial_number == other.serial_number &&
			this->max_component_len == other.max_component_len &&
			this->file_system_flags == other.file_system_flags &&
			this->file_system_name == other.file_system_name &&
			this->drive_type == other.drive_type)
	{return true;}


	return false;
}

Volume::~Volume() noexcept {
	root_path = nullptr;
	volume_name = nullptr;
	serial_number = 0;
	max_component_len = 0;
	file_system_flags = 0;

	delete root_path;
	delete volume_name;
	delete file_system_name;
}


// GETTERS

const wchar_t* Volume::rootPath() const noexcept {
	return root_path;
}

const wchar_t* Volume::volumeName() const noexcept {
	return volume_name;
}

const ulint Volume::serialNumber() const noexcept {
	return serial_number;
}

const ulint  Volume::maxComponentLength() const noexcept {
	return max_component_len;
}

const ulint Volume::fileSystemFlags() const noexcept {
	return file_system_flags;
}

const wchar_t* Volume::fileSystemName() const noexcept {
	return file_system_name;
}

const wchar_t* Volume::driveType() const noexcept {
	return drive_type;
}

// GETTERS END

const void Volume::printInfo() const noexcept {
	std::wcout << L"Drive name:\t" << volume_name << "\n";
	std::wcout << L"\t0) Root path:\t\t" << root_path << "\n";
	std::wcout << L"\t1) Drive type:\t\t" << drive_type << "\n";
	std::wcout << L"\t2) File system name:\t\t" << file_system_name << "\n";
	std::wcout << L"\t5) File system flags:\t\t" << file_system_flags << "\n";
	std::wcout << L"\t3) Serial number:\t\t" << serial_number << "\n";
	std::wcout << L"\t4) Max component length:\t\t" << max_component_len << "\n\n";
}