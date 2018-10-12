#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Message : public ActiveCampaign, public AutoRegister<Message>
{

public:
	Message(const Config * config) :
		ActiveCampaign(config,
			{	"message_add", "message_delete", "message_delete_list", "message_edit", "message_list",
				"message_template_add", "message_template_delete", "message_template_delete_list",
				"message_template_edit", "message_template_export", "message_template_import",
				"message_template_list", "message_template_view", "message_view"
			},
			{	std::bind(&Message::messageAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateExport, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateImport, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageTemplateView, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Message::messageView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const Config * config)
	{
		return std::make_unique<Message>(config);
	}

	static std::string GetFactoryName()
	{
		return "Message";
	}

	json messageAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json messageDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json messageList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageTemplateAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json messageTemplateDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageTemplateDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageTemplateEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json messageTemplateExport(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageTemplateImport(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json messageTemplateList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageTemplateView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json messageView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
