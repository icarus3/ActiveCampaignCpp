#ifndef SINGLESIGNON_HPP
#define SINGLESIGNON_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class SingleSignOn : public ActiveCampaign, public AutoRegister<SingleSignOn>
{

public:
	SingleSignOn(const Config * config) :
		ActiveCampaign(config,
			{ "singlesignon"
			},
			{ std::bind(&SingleSignOn::singlesignon, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const Config * config)
	{
		return std::make_unique<SingleSignOn>(config);
	}

	static std::string GetFactoryName()
	{
		return "SingleSignOn";
	}

	json singlesignon(const std::string & action, const json & data)
	{
		return post(action, data);
	}
};

#endif
