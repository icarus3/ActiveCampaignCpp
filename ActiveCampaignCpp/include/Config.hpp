#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

#include "Exception.hpp"

class Config
{
	std::string m_url;
	std::string m_apiKey;
	std::string m_outputFormat;

public:
	Config(const std::string & url, const std::string & apiKey)
		: m_url(url), m_apiKey(apiKey), m_outputFormat("json")
	{
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
};

#endif
