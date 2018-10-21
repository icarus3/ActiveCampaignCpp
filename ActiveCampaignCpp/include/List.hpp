#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class List : public ActiveCampaign, public AutoRegister<List>
{

public:
	List(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{	"list_add", "list_list", "list_delete", "list_delete_list", "list_edit", "list_field_add",
				"list_field_delete", "list_field_edit", "list_field_view", "list_paginator",
				"list_view"
			},
			{	std::bind(&List::listAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listFieldAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listFieldDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listFieldEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listFieldView, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listPaginator, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&List::listView, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<List>(config);
	}

	static std::string GetFactoryName()
	{
		return "List";
	}

	json listAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json listList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json listDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json listDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json listEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json listFieldAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}
	
	json listFieldDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}
	
	json listFieldEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json listFieldView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
		
	json listPaginator(const std::string & action, const json & data)
	{
		return get(action, data);
	}
	
	json listView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};


#endif
