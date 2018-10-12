#ifndef ACTIVECAMPAIGNFACTORY_HPP
#define ACTIVECAMPAIGNFACTORY_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "Account.hpp"
#include "Address.hpp"
#include "List.hpp"
#include "HttpOpsFactory.hpp"
#include "ActiveCampaign.hpp"

class ActiveCampaignFactory
{
	using TCreateMethod = std::unique_ptr<ActiveCampaign>(*)(const Config * config);

public:
	ActiveCampaignFactory() = delete;

	static bool Register(const std::string name, TCreateMethod createFunc)
	{
		auto it = s_methods.find(name);
		if (it == s_methods.end())
		{
			s_methods[name] = createFunc;
			return true;
		}
		return false;
	}

	static std::unique_ptr<ActiveCampaign> Create(const std::string& name, const Config * config)
	{
		auto it = s_methods.find(name);
		if (it != s_methods.end())
		{
			return it->second(config);
		}
		return nullptr;
	}

private:
	static std::map<std::string, TCreateMethod> s_methods;
};

std::map<std::string, ActiveCampaignFactory::TCreateMethod> ActiveCampaignFactory::s_methods;

#endif
