#ifndef URLHANDLER_HPP
#define URLHANDLER_HPP

#include <iostream>

#include "Config.hpp"
#include "json.hpp"
#include "LibCurl.hpp"

using json = nlohmann::json;

class UrlHandler
{
public:
	static std::string makeParameters(const Config * config, const json & data)
	{
		std::string url = "";
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

			CURL * curl = LibCurl::getLibCurlImpl()->getCurl();
			char *output = curl_easy_escape(curl, strKey.c_str(), (int)strKey.length());
			if (output)
			{
				url += "&" + std::string(output);
				curl_free(output);
			}

			output = curl_easy_escape(curl, strVal.c_str(), (int)strVal.length());
			if (output)
			{
				url += "=" + std::string(output);
				curl_free(output);
			}
		}
		url = url.replace(0, 1, "");

		return url;
	}

	static std::string makeUrl(const std::string& action, const Config * config)
	{
		return config->getUrl() + "/admin/api.php?api_action=" + action
								+ "&api_output=" + config->getFormat()
								+ "&api_key=" + config->getApiKey();;
	}

	static std::string makeUrlWithParameters(const std::string& action, const Config * config, const json & data)
	{
		return makeUrl(action, config) + "&" + makeParameters(config, data);
	}
};

#endif