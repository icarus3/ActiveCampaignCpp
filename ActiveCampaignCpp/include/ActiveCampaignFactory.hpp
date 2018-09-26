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

	ActiveCampaignFactory(Config * config)
	{
		m_factories["account"] = [=] {
			return std::make_unique<Account>(config);
		};
	}

	std::unique_ptr<ActiveCampaign> makeActiveCampaign(const std::string& name)
	{
		return m_factories[name]();
	}
};

#endif
