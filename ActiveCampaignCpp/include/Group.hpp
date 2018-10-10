#ifndef GROUP_HPP
#define GROUP_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Group : public ActiveCampaign
{

public:
	Group(const Config * config) :
		ActiveCampaign(config,
			{	"group_add", "group_delete", "group_delete_list",
				"group_edit", "group_list", "group_view"
			},
			{	std::bind(&Group::groupAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Group::groupDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Group::groupDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Group::groupEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Group::groupList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Group::groupView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json groupAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json groupDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json groupDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json groupEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json groupList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json groupView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
