#pragma once

#include <string>
#include <miniocpp/client.h>
#include <memory>
#include <vector>
#include <filesystem>
#include <fstream>

namespace MinioApi {
	class MinioClient {
	public:
		MinioClient(std::string host, std::string username, std::string password);
		
		bool PutObject(const std::string& bucketName, const std::string& objectName, const std::string& pathToObject);
		
		bool BucketExists(const std::string& bucketName);

		std::vector<std::string> GetBucketList();

		~MinioClient();
	private:
		minio::creds::StaticProvider provider_;
		std::unique_ptr<minio::s3::Client> client_;
	};
}