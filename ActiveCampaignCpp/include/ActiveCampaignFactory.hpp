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
	std::map<std::string, std::function<std::unique_ptr<ActiveCampaign>()>> m_factories;
public:

	ActiveCampaignFactory(std::unique_ptr<Config> config)
	{
		m_factories["account/view"] = [&config] {
			return std::make_unique<Account>("account_view", HttpOpsFactory().makeHttpOps("GET"), std::move(config));
		};
	}

	std::unique_ptr<ActiveCampaign> makeActiveCampaign(const std::string& name)
	{
		return m_factories[name]();
	}
};

#endif
