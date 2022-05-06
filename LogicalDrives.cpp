#include "LogicalDrives.h"


LogicalDrives::LogicalDrives() noexcept {
	findDrives();
}

LogicalDrives::~LogicalDrives() noexcept {

}

void LogicalDrives::printInfo() {
	for (const Volume vol : DRIVES) {
		vol.printInfo();
	}
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
		LPDWORD serial_number;
		LPDWORD max_component_len;
		LPDWORD fs_flags;
		LPWSTR fs_name[MAX_PATH];

		if (GetVolumeInformationW(	drive_root_path,
									*volume_name, 
									ARRAYSIZE(volume_name) - 1, 
									serial_number, 
									max_component_len, 
									fs_flags, 
									*fs_name, 
									ARRAYSIZE(fs_name) - 1)) 
		{
			UINT drive_type_code{ GetDriveTypeW(drive_root_path) };

			const Volume vol{ drive_root_path, *volume_name, serial_number, max_component_len, fs_flags, *fs_name, detectDriveType(drive_type_code)};
			DRIVES.push_back(vol);
		};
	}
}

const wchar_t* LogicalDrives::detectDriveType(const UINT drive_type_code) {
	return types[drive_type_code];
}