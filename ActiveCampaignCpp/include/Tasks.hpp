#ifndef TASKS_HPP
#define TASKS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Tasks : public ActiveCampaign
{

public:
	Tasks(const Config * config) :
		ActiveCampaign(config,
			{ "tasks_get"
			},
			{ std::bind(&Tasks::tasksGet, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json tasksGet(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
