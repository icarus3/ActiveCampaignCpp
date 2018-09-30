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
			{ "list_add" },
			{ std::bind(&List::listAdd, this, std::placeholders::_1, std::placeholders::_2) })
	{
	}

	json listAdd(const std::string & action, const json & data)
	{
		std::string url = UrlHandler::makeUrl(action, m_config);
		std::string parameters = UrlHandler::makeParameters(m_config, data);

		std::unique_ptr<HttpOps> httpGet = HttpOpsFactory().makeHttpOps("POST");
		httpGet->sendData(url, parameters);

		return nullptr;
	}

};


#endif
