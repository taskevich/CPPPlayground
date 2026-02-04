#include <iostream>

#include "core/include/utils.h"
#include "core/include/minio.h"

int main() {
	std::string tempPath = Utils::getTempPath();
	std::string desktopPath = Utils::getDesktopPath();
	std::string appdataPath = Utils::getAppDataPath();
	std::cout << tempPath << std::endl;
	std::cout << desktopPath << std::endl;
	std::cout << appdataPath << std::endl;

	std::string minioHost = "127.0.0.1:9000";
	std::string minioUsername = "minioadmin";
	std::string minioPassword = "minioadmin";
	
	MinioApi::MinioClient client(minioHost, minioUsername, minioPassword);

	auto bucketList = client.GetBucketList();
	for (const std::string& bucketName : bucketList) {
		std::cout << bucketName << std::endl;
	}

	std::cin;

	return 0;
}
