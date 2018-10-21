#ifndef WEBHOOK_HPP
#define WEBHOOK_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class WebHook : public ActiveCampaign, public AutoRegister<WebHook>
{

public:
	WebHook(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{	"webhook_add", "webhook_delete", "webhook_edit",
				"webhook_events", "webhook_list", "webhook_view"
			},
			{	std::bind(&WebHook::webHookAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&WebHook::webHookDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&WebHook::webHookEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&WebHook::webHookEvents, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&WebHook::webHookList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&WebHook::webHookView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<WebHook>(config);
	}

	static std::string GetFactoryName()
	{
		return "WebHook";
	}

	json webHookAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json webHookDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json webHookEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json webHookEvents(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json webHookList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json webHookView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
