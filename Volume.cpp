#include "pch.h"
#include "Volume.h"

Volume:: Volume(const wchar_t* root_path,
				const wchar_t* volume_name,
				const unsigned long int serial_number,
				const unsigned long int max_component_len,
				const unsigned long int fs_flags,
				const wchar_t* fs_name) noexcept :
root_path{std::wstring{root_path}},
volume_name{std::wstring{volume_name}},
serial_number{serial_number},
max_component_len{max_component_len},
file_system_flags{ fs_flags },
file_system_name{ std::wstring{fs_name} } 
{}

Volume::Volume(const Volume& other) noexcept :
	root_path{other.root_path},
	volume_name{other.volume_name},
	serial_number{other.serial_number},
	max_component_len{other.max_component_len},
	file_system_flags{other.file_system_flags},
	file_system_name{other.file_system_name} 
{}

Volume::Volume(Volume&& other) noexcept :
	root_path{other.root_path},
	volume_name{other.volume_name},
	serial_number{other.serial_number},
	max_component_len{other.max_component_len},
	file_system_flags{other.file_system_flags},
	file_system_name{other.file_system_name}
{
	other.root_path = std::wstring{ L"moved" };
	other.volume_name = std::wstring{ L"moved" };
	other.serial_number = NULL;
	other.max_component_len = NULL;
	other.file_system_flags - NULL;
	other.file_system_name = std::wstring{ L"moved" };
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

	other.root_path = std::wstring{ L"moved" };
	other.volume_name = std::wstring{ L"moved" };
	other.serial_number = NULL;
	other.max_component_len = NULL;
	other.file_system_flags = NULL;
	other.file_system_name = std::wstring{ L"moved" };

	return *this;
}

bool Volume::operator==(const Volume& other) noexcept {
	if (
			this->root_path == other.root_path &&
			this->volume_name == other.volume_name &&
			this->serial_number == other.serial_number &&
			this->max_component_len == other.max_component_len&&
			this->file_system_flags == other.file_system_flags &&
			this->file_system_name == other.file_system_name) 
	{return true;}


	return false;
}


// GETTERS

std::wstring Volume::rootPath() const noexcept {
	return root_path;
}

std::wstring Volume::volumeName() const noexcept {
	return volume_name;
}

uint64_t Volume::serialNumber() const noexcept {
	return serial_number;
}

uint64_t Volume::maxComponentLength() const noexcept {
	return max_component_len;
}

uint64_t Volume::fileSystemFlags() const noexcept {
	return file_system_flags;
}

std::wstring Volume::fileSystemName() const noexcept {
	return file_system_name;
}