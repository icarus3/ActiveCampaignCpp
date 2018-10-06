#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

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

	json accountView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

};

#endif