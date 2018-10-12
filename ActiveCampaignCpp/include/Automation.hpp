#ifndef AUTOMATION_HPP
#define AUTOMATION_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "AutoRegister.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Automation : public ActiveCampaign, public AutoRegister<Automation>
{

public:
	Automation(const Config * config) :
		ActiveCampaign(config,
			{ "automation_contact_add", "automation_contact_list", "automation_contact_remove", "automation_contact_view",
				"automation_list"
			},
			{	std::bind(&Automation::automationContactAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Automation::automationContactList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Automation::automationContactRemove, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Automation::automationContactView, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Automation::automationList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const Config * config)
	{
		return std::make_unique<Automation>(config);
	}

	static std::string GetFactoryName()
	{
		return "Automation";
	}

	json automationContactAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json automationContactList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json automationContactRemove(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json automationContactView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json automationList(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
