#ifndef BRANDING_HPP
#define BRANDING_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "AutoRegister.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Branding : public ActiveCampaign, public AutoRegister<Branding>
{

public:
	Branding(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{	"branding_edit",
				"branding_view"
			},
			{	std::bind(&Branding::brandingEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Branding::brandingView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Branding>(config);
	}

	static std::string GetFactoryName()
	{
		return "Branding";
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
