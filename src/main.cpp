#include <iostream>

#include "core/include/utils.h"
#include "core/include/minio.h"

void playMinio() {
	std::string minioHost = "http://10.1.0.71:9000";
	std::string minioUsername = "minioadmin";
	std::string minioPassword = "minioadmin";

	MinioApi::MinioClient client(minioHost, minioUsername, minioPassword);

	std::cout << "Bucket list:" << std::endl;
	auto bucketList = client.GetBucketList();
	for (const std::string& bucketName : bucketList) {
		std::cout << "\tBucket name: " << bucketName << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Putting file:" << std::endl;
	std::string bucketName = "ctests";
	std::string desktopPath = Utils::getDesktopPath();
	std::string randomPath = Utils::getRandomFilePath(desktopPath);
	std::string fileName = Utils::getFileName(randomPath);

	bool isPut = client.PutObject(bucketName, fileName, randomPath);
	std::cout << "\tIs putted: " << std::endl << std::endl;

	bool bucketExists = client.BucketExists(bucketName);

	std::cout << "Bucket exists " << bucketExists << std::endl;
}

void playApi() {
	std::string tempPath = Utils::getTempPath();
	std::string desktopPath = Utils::getDesktopPath();
	std::string appdataPath = Utils::getAppDataPath();
	std::string randomPath = Utils::getRandomFilePath(desktopPath);
	std::string fileName = Utils::getFileName(randomPath);
	std::string fileExtension = Utils::getFileExtension(randomPath);

	std::cout << "Random path: " << randomPath << " name: " << fileName << " extension: " << fileExtension << std::endl;
	std::cout << tempPath << std::endl;
	std::cout << desktopPath << std::endl;
	std::cout << appdataPath << std::endl;
}

int main() {

	playMinio();
	// playApi();
	std::cin;

	return 0;
}
