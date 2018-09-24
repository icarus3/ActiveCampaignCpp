#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "Httpops.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Account : public ActiveCampaign
{
	std::string m_action;
	std::unique_ptr<HttpOps> m_httpOps;
	std::unique_ptr<Config> m_config;
public:
	Account(const std::string & action,
		std::unique_ptr<HttpOps> httpOps,
		std::unique_ptr<Config> config)
		:m_action(action), m_httpOps(std::move(httpOps)), m_config(std::move(config))
	{
	}

	json api(const json & data)
	{
		std::string url;
		return m_httpOps->sendData(url, data);
	}
};

#endif