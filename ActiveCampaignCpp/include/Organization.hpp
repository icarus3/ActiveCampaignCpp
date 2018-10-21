#ifndef ORGANIZATION_HPP
#define ORGANIZATION_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Organization : public ActiveCampaign, public AutoRegister<Organization>
{

public:
	Organization(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{ "organization_list"
			},
			{ std::bind(&Organization::organizationList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Organization>(config);
	}

	static std::string GetFactoryName()
	{
		return "Organization";
	}

	json organizationList(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
