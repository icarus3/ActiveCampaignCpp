#ifndef ORGANIZATION_HPP
#define ORGANIZATION_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Organization : public ActiveCampaign
{

public:
	Organization(const Config * config) :
		ActiveCampaign(config,
			{ "organization_list"
			},
			{ std::bind(&Organization::organizationList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json organizationList(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
