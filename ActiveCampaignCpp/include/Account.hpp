#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "json.hpp"
#include "Exception.hpp"
#include "Config.hpp"
#include "Httpops.hpp"
#include "HttpOpsFactory.hpp"
#include "ActiveCampaign.hpp"
#include "UrlHandler.hpp"

using json = nlohmann::json;

class Account : public ActiveCampaign
{
	const Config * m_config;
	const std::map< const std::string, std::function<json(const std::string & action, const json & data)> > m_actions;

public:
	Account(const Config * config) 
			: m_config(config), m_actions
			{
				{"account_view", std::bind(&Account::accountView, this, std::placeholders::_1, std::placeholders::_2)}
			}
	{
		int i = 0;
	}

	void getSupportedActions(std::vector<std::string> & actions)
	{
		actions.reserve(m_actions.size());
		for (auto keyValue : m_actions)
		{
			actions.push_back(keyValue.first);
		}
	}

	json accountView(const std::string & action,  const json & data)
	{
		(void)data;
		std::string url = UrlHandler::makeUrl(action, m_config, data);
		return nullptr;
	}

	json api(const std::string & action, const json & data) override
	{
		if(m_actions.find(action) == m_actions.end())
		{
			throw new Exception("Action:" + action + " not supported.");
		}

		std::function<json(const std::string & action, const json &)> func =  m_actions.at(action);
		return func(action, data);
	}
};

#endif