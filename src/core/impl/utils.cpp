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

	// Получение случайного полного пути до файла
	std::string getRandomFilePath(const std::string& startPath) {
		std::vector<std::string> filePaths;

		for (const auto& entry : std::filesystem::directory_iterator(
			startPath, std::filesystem::directory_options::skip_permission_denied)) {
			if (!entry.is_regular_file()) {
				continue;
			}
			filePaths.push_back(entry.path().string());
		}

		if (filePaths.empty()) {
			return "";
		}

		return filePaths[rand() % filePaths.size()];
	}

	// Получение расширения файла из строки
	std::string getFileExtension(const std::string& filePath) {
		size_t pos = filePath.rfind('.');
		if (pos == std::string::npos || pos == 0) {
			return "";
		}

		size_t slashPos = filePath.find_last_of("/\\");
		if (slashPos != std::string::npos && pos <= slashPos) {
			return "";
		}
		return filePath.substr(pos);
	}

	// Получение имени файла из пути
	std::string getFileName(const std::string& filePath) {
		size_t pos = filePath.find_last_of("/\\");
		if (pos == std::string::npos) {
			return filePath;
		}
		return filePath.substr(pos + 1);
	}
}