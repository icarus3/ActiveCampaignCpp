#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Settings : public ActiveCampaign, public AutoRegister<Settings>
{

public:
	Settings(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{ "settings_list"
			},
			{ std::bind(&Settings::settingsList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Settings>(config);
	}

	static std::string GetFactoryName()
	{
		return "Settings";
	}

	json settingsList(const std::string & action, const json & data)
	{
		return post(action, data);
	}
};

#endif
