#include "minio.h"

namespace MinioApi {
	MinioClient::MinioClient(std::string host, std::string username, std::string password) : provider_(username, password) {
		minio::s3::BaseUrl baseUrl(host, false);
		this->client_ = std::make_unique<minio::s3::Client>(baseUrl, &this->provider_);
		this->client_->IgnoreCertCheck(true);
	}

	bool MinioClient::PutObject(std::string& bucketName, std::string& objectName, std::string& pathToObject) {
		std::filesystem::path p = std::filesystem::absolute(pathToObject);
		std::ifstream file(p, std::ios::binary | std::ios::ate);
		
		if (!file.is_open()) {
			std::cerr << "Error to open " << pathToObject << std::endl;
			return false;
		}

		int fileSize = file.tellg();
		file.seekg(0, std::ios::beg);

		minio::s3::PutObjectArgs args(file, fileSize, 0);

		args.bucket = bucketName;
		args.object = objectName;

		auto response = this->client_->PutObject(args);
		if (!response) {
			std::cerr << response.Error() << std::endl;
			return false;
		}

		return true;
	}

	std::vector<std::string> MinioClient::GetBucketList() {
		std::vector<std::string> result;
		
		auto response = this->client_->ListBuckets();
		if (!response) {
			std::cerr << response.Error() << std::endl;
			return result;
		}

		for (const auto& bucket : response.buckets) {
			result.push_back(bucket.name);
		}

		return result;
	}

	MinioClient::~MinioClient() { }
}