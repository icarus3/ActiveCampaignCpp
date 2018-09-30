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

public:
	Account(const Config * config) :
		ActiveCampaign( config,
						{ "account_view" },
						{ std::bind(&Account::accountView, this, std::placeholders::_1, std::placeholders::_2) } )
	{
	}

	json accountView(const std::string & action,  const json & data)
	{
		(void)data;
		std::string url = UrlHandler::makeUrlWithParameters(action, m_config, data);
		std::unique_ptr<HttpOps> httpGet = HttpOpsFactory().makeHttpOps("GET");
		httpGet->sendData(url);

		return nullptr;
	}

};

#endif