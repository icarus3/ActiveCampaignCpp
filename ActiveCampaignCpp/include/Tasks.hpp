#ifndef TASKS_HPP
#define TASKS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Tasks : public ActiveCampaign, public AutoRegister<Tasks>
{

public:
	Tasks(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{ "tasks_get"
			},
			{ std::bind(&Tasks::tasksGet, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Tasks>(config);
	}

	static std::string GetFactoryName()
	{
		return "Tasks";
	}

	json tasksGet(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
