#include "minio.h"

namespace MinioApi {
	MinioClient::MinioClient(std::string host, std::string username, std::string password) : provider_(username, password) {
		minio::s3::BaseUrl baseUrl(host);
		this->client_ = std::make_unique<minio::s3::Client>(baseUrl, &this->provider_);
		this->client_->IgnoreCertCheck(true);
	}

	std::vector<std::string> MinioClient::GetBucketList() {
		std::vector<std::string> result;

		auto response = this->client_->ListBuckets();
		for (const auto& bucket : response.buckets) {
			result.push_back(bucket.name);
		}
		return result;
	}

	MinioClient::~MinioClient() {

	}
}