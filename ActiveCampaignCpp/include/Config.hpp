#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

#include "Exception.hpp"
#include "curl/curl.h"

class Config
{
	std::string m_url;
	std::string m_apiKey;
	std::string m_outputFormat;
	CURL * m_curl;

public:
	Config(const std::string & url, const std::string & apiKey)
		: m_url(url), m_apiKey(apiKey), m_outputFormat("json"), m_curl(curl_easy_init())
	{
		if (!m_curl)
		{
			throw Exception("Unable to initialize curl");
		}
	}

	~Config()
	{
		curl_easy_cleanup(m_curl);
	}

	std::string getApiKey() const
	{
		return m_apiKey;
	}

	std::string getUrl() const
	{
		return m_url;
	}

	std::string getFormat() const
	{
		return 	m_outputFormat;
	}

	CURL * getCurl() const
	{
		return m_curl;
	}

};

#endif
