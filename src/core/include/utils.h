#pragma once

#include <string>
#include <Shlobj.h>
#include <filesystem>
#include <random>

namespace Utils {
	// Получение полного пути до %appdata%
	std::string getAppDataPath();

	// Получение пути до рабочего стола
	std::string getDesktopPath();

	// Получение пути до %temp%
	std::string getTempPath();

	// Получение случайного полного пути до файла
	std::string getRandomFilePath(const std::string& startPath);

	// Получение расширения файла из строки
	std::string getFileExtension(const std::string& filePath);

	// Получение имени файла из пути
	std::string getFileName(const std::string& filePath);
}