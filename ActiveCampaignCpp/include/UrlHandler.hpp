#ifndef URLHANDLER_HPP
#define URLHANDLER_HPP

#include <iostream>

#include "Config.hpp"
#include "json.hpp"


class UrlHandler
{
public:
	static std::string makeUrl(const std::string& action, const Config * config, const json & data = nullptr)
	{
		std::string url = config->getUrl() 
							+ "/admin/api.php?api_action=" + action 
							+ "&result_output=" + config->getFormat()
							+ "&api_key=" + config->getApiKey();

		for (auto item : data.items())
		{
			std::string strKey = item.key();
			std::string strVal;

			json::value_type val = item.value();
			if (val.type() == json::value_t::string)
			{
				strVal = val.get<std::string>();
			}
			else if (val.type() == json::value_t::number_integer)
			{
				 strVal = std::to_string(val.get<int>());
			}

			char *output = curl_easy_escape(config->getCurl(), strKey.c_str(), (int)strKey.length());
			if (output)
			{
				url += "&" + std::string(output);
				curl_free(output);
			}

			output = curl_easy_escape(config->getCurl(), strVal.c_str(), (int)strVal.length());
			if (output)
			{
				url += "=" + std::string(output);
				curl_free(output);
			}
		}

		return url;
	}
};

#endif