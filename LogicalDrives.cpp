#include "pch.h"
#include "LogicalDrives.h"

LogicalDrives::LogicalDrives() {
	//try {
		findDrives();
	//}
	//catch (const DriveException& ex) {
		//throw ex;
	//}
}

LogicalDrives::~LogicalDrives() noexcept {

}

void LogicalDrives::printInfo() {
	for (const Volume vol : this->DRIVES) {
		vol.printInfo();
	}
}

void LogicalDrives::findDrives() {

	LPWSTR drives{ reinterpret_cast<LPWSTR>(malloc(MAX_PATH)) };
	DWORD drive_strings{ GetLogicalDriveStringsW(MAX_PATH, drives) };
	if (drive_strings == 0) {
		throw DriveException(GetLastError(), L"Drives not found");
	};

	for (int iter = 0; iter < MAX_PATH; iter = iter + 4) {
		LPWSTR root_path{&drives[iter]};
		LPWSTR volume_name{ reinterpret_cast<LPWSTR>(malloc(MAX_PATH)) };
		DWORD serial_number;
		DWORD max_component_len;
		DWORD fs_flags;
		LPWSTR fs_name{ reinterpret_cast<LPWSTR>(malloc(MAX_PATH))};

		if (GetVolumeInformationW(
			root_path,
			volume_name,
			MAX_PATH,
			&serial_number,
			&max_component_len,
			&fs_flags,
			fs_name,
			MAX_PATH))
		{
			UINT drive_type_code{ GetDriveTypeW(root_path) };
			const Volume vol{ root_path, volume_name, serial_number, max_component_len, fs_flags, fs_name, detectDriveType(drive_type_code) };
			DRIVES.push_back(vol);
		}
		//else {
			//throw DriveException(GetLastError(), L"Can not get information about drive");
		//};
	}
};

const wchar_t* LogicalDrives::detectDriveType(const UINT drive_type_code) {
	return types[drive_type_code].c_str();
}