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
		
		bool PutObject(std::string& bucketName, std::string& objectName, std::string& pathToObject);

		std::vector<std::string> GetBucketList();

		~MinioClient();
	private:
		minio::creds::StaticProvider provider_;
		std::unique_ptr<minio::s3::Client> client_;
	};
}