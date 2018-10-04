#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "json.hpp"
#include "Exception.hpp"
#include "Config.hpp"
#include "Httpops.hpp"
#include "HttpOpsFactory.hpp"
#include "ActiveCampaign.hpp"
#include "UrlHandler.hpp"

using json = nlohmann::json;

class List : public ActiveCampaign
{

public:
	List(const Config * config) :
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
	}

	json listAdd(const std::string & action, const json & data)
	{
		std::string url = UrlHandler::makeUrl(action, m_config);
		std::string parameters = UrlHandler::makeParameters(m_config, data);

		std::unique_ptr<HttpOps> httpPost = HttpOpsFactory().makeHttpOps("POST");
		return httpPost->sendData(url, parameters);
	}

	json listList(const std::string & action, const json & data)
	{
		std::string url = UrlHandler::makeUrlWithParameters(action, m_config, data);
		std::unique_ptr<HttpOps> httpGet = HttpOpsFactory().makeHttpOps("GET");
		return httpGet->sendData(url);
	}

	json listDelete(const std::string & action, const json & data)
	{
		return nullptr;
	}

	json listDeleteList(const std::string & action, const json & data)
	{
		return nullptr;
	}

	json listEdit(const std::string & action, const json & data)
	{
		return nullptr;
	}

	json listFieldAdd(const std::string & action, const json & data)
	{
		return nullptr;
	}
	
	json listFieldDelete(const std::string & action, const json & data)
	{
		return nullptr;
	}
	
	json listFieldEdit(const std::string & action, const json & data)
	{
		return nullptr;
	}

	json listFieldView(const std::string & action, const json & data)
	{
		return nullptr;
	}
		
	json listPaginator(const std::string & action, const json & data)
	{
		return nullptr;
	}
	
	json listView(const std::string & action, const json & data)
	{
		return nullptr;
	}

};


#endif
