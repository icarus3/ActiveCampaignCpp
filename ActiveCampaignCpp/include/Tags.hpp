#ifndef TAGS_HPP
#define TAGS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Tags : public ActiveCampaign, public AutoRegister<Tags>
{

public:
	Tags(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{ "tags_list"
			},
			{ std::bind(&Tags::tagsList, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Tags>(config);
	}

	static std::string GetFactoryName()
	{
		return "Tags";
	}

	json tagsList(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
