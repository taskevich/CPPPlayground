#include "minio.h"

namespace MinioApi {
	MinioClient::MinioClient(std::string host, std::string username, std::string password) : provider_(username, password) {
		minio::s3::BaseUrl baseUrl(host);
		this->client_ = std::make_unique<minio::s3::Client>(baseUrl, &this->provider_);
	}

	std::vector<std::string> MinioClient::GetBucketList() {
		std::vector<std::string> result;

		auto listBuckets = this->client_->ListBuckets();
		if (!listBuckets.buckets.size()) {
			return {};
		}

		for (const auto& bucket : listBuckets.buckets) {
			result.push_back(bucket.name);
		}
		return result;
	}

	MinioClient::~MinioClient() {

	}
}