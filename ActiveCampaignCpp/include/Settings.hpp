#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Settings : public ActiveCampaign
{

public:
	Settings(const Config * config) :
		ActiveCampaign(config,
			{ "settings_list"
			},
			{ std::bind(&Settings::settingsList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json settingsList(const std::string & action, const json & data)
	{
		return post(action, data);
	}
};

#endif
