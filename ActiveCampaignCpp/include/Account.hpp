#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "AutoRegister.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Account : public ActiveCampaign, public AutoRegister<Account>
{

public:
	Account(const std::shared_ptr<Config> & config) :
		ActiveCampaign( config,
						{ "account_view" },
						{ std::bind(&Account::accountView, this, std::placeholders::_1, std::placeholders::_2) } )
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Account>(config);
	}

	static std::string GetFactoryName()
	{
		return "Account";
	}

	json accountView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

};

#endif
