#ifndef TAGS_HPP
#define TAGS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Tags : public ActiveCampaign
{

public:
	Tags(const Config * config) :
		ActiveCampaign(config,
			{ "tags_list"
			},
			{ std::bind(&Tags::tagsList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json tagsList(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
