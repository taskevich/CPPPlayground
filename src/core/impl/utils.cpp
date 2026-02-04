#include "../include/utils.h"

namespace Utils {
	// Получение полного пути до %appdata%
	std::string getAppDataPath() {
		char* path = new char[MAX_PATH];
		SHGetFolderPath(nullptr, CSIDL_APPDATA, NULL, 0, path);
		return path;
	}

	// Получение пути до рабочего стола
	std::string getDesktopPath() {
		char* path = new char[MAX_PATH];
		SHGetFolderPath(nullptr, CSIDL_DESKTOP, NULL, 0, path);
		return path;
	}

	// Получение пути до %temp%
	std::string getTempPath() {
		char* path = std::getenv("temp");
		return path;
	}
}