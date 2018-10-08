#ifndef BRANDING_HPP
#define BRANDING_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Branding : public ActiveCampaign
{

public:
	Branding(const Config * config) :
		ActiveCampaign(config,
			{	"branding_edit",
				"branding_view"
			},
			{	std::bind(&Branding::brandingEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Branding::brandingView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json brandingEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json brandingView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
