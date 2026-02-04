#pragma once

#include <string>
#include <Shlobj.h>

namespace Utils {
	// Получение полного пути до %appdata%
	std::string getAppDataPath();

	// Получение пути до рабочего стола
	std::string getDesktopPath();

	// Получение пути до %temp%
	std::string getTempPath();
}