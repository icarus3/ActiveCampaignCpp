#ifndef HTTPOPS_HPP
#define HTTPOPS_HPP

#include <string>

#include "json.hpp"
#include "LibCurl.hpp"

using json = nlohmann::json;

namespace
{
	static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
	{
		((std::string*)userp)->append((char*)contents, size * nmemb);
		return size * nmemb;
	}
};

class HttpOps
{
public:

	virtual json sendData(const std::string & url, const std::string& data = "") = 0;
	virtual ~HttpOps() = default;
};

class HttpGetOps : public HttpOps
{

public:

	json sendData(const std::string & url, const std::string& data ) override
	{
		(void)data;

		LibCurl* libCurl = LibCurl::getLibCurlImpl();
		CURL * curl = libCurl->getCurl();
		std::string readBuffer;

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		if (curl_easy_perform(curl) != CURLE_OK)
		{
			throw new Exception("curl_easy_perform() failed");
		}

		try
		{
			return json::parse(readBuffer);
		}
		catch (const json::parse_error&)
		{
			throw new Exception("Invalid response received" + readBuffer);
		}

		return nullptr;
	}
};

class HttpPostOps : public HttpOps
{

public:

	json sendData(const std::string & url, const std::string & postParams) override
	{
		LibCurl* libCurl = LibCurl::getLibCurlImpl();
		CURL * curl = libCurl->getCurl();
		std::string readBuffer;

		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_HEADER, 0);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postParams.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		if (curl_easy_perform(curl) != CURLE_OK)
		{
			throw new Exception("curl_easy_perform() failed");
		}

		try
		{
			return json::parse(readBuffer);
		}
		catch (const json::parse_error&)
		{
			throw new Exception("Invalid response received" + readBuffer);
		}

		return nullptr;
	}
};

#endif