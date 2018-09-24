#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

class Config
{
	std::string m_apiKey;
	std::string m_outputFormat;

public:
	Config(const std::string & apiKey) : m_apiKey(apiKey), m_outputFormat("json")
	{
	}

	std::string getApiKey()
	{
		return m_apiKey;
	}
};

#endif
