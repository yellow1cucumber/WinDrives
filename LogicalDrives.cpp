#include "pch.h"
#include "LogicalDrives.h"


LogicalDrives::LogicalDrives() noexcept {

}

LogicalDrives::~LogicalDrives() noexcept {

}

void LogicalDrives::findDrives() {

	LPWSTR buffer[MAX_PATH];
	DWORD drive_strings{ GetLogicalDriveStringsW(ARRAYSIZE(buffer)-1, *buffer) };
	if (drive_strings == 0) {
		DWORD error{ std::move(GetLastError()) };
		std::wcout << error << "\n";
		throw error;
	};

	for (LPWSTR drive_root_path : buffer) {
		LPWSTR volume_name[MAX_PATH];
		LPDWORD serial_number[MAX_PATH];
		LPDWORD max_component_len[MAX_PATH];
		LPDWORD fs_flags[MAX_PATH];
		LPWSTR fs_name[MAX_PATH];
		if (GetVolumeInformationW(	drive_root_path,
									*volume_name, 
									ARRAYSIZE(volume_name) - 1, 
									*serial_number, 
									*max_component_len, 
									*fs_flags, 
									*fs_name, 
									ARRAYSIZE(fs_name) - 1)) 
		{
			UINT drive_type{ GetDriveTypeW(drive_root_path) };


		};
	}

}