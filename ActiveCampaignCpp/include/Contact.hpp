#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Contact : public ActiveCampaign
{

public:
	Contact(const Config * config) :
		ActiveCampaign(config,
			{	"contact_add", "contact_automation_list", "contact_delete", "contact_delete_list",
				"contact_edit", "contact_list", "contact_note_add", "contact_note_delete",
				"contact_note_edit", "contact_paginator", "contact_sync", "contact_tag_add",
				"contact_tag_remove", "contact_view", "contact_view_email", "contact_view_hash"
			},
			{	std::bind(&Contact::contactAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactAutomationList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactNoteAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactNoteDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactNoteEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactPaginator, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactSync, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactTagAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactTagRemove, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactView, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactViewEmail, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Contact::contactViewHash, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json contactAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactAutomationList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactNoteAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactNoteDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactNoteEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactPaginator(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactSync(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactTagAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactTagRemove(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json contactView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactViewEmail(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json contactViewHash(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
