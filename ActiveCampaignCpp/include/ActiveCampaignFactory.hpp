#ifndef ACTIVECAMPAIGNFACTORY_HPP
#define ACTIVECAMPAIGNFACTORY_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "Account.hpp"
#include "HttpOpsFactory.hpp"
#include "ActiveCampaign.hpp"

class ActiveCampaignFactory
{
	std::map<std::string, std::function<std::unique_ptr<ActiveCampaign>()>> factories;
public:

	ActiveCampaignFactory()
	{
		factories["account/view"] = [] {
			return std::make_unique<Account>("account_view", HttpOpsFactory().makeHttpOps("GET"));
		};
	}

	std::unique_ptr<ActiveCampaign> makeActiveCampaign(const std::string& name)
	{
		return factories[name]();
	}
};

#endif
