#ifndef ADDRESS_HPP
#define ADDRESS_HPP

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

class Address : public ActiveCampaign
{

public:
	Address(const Config * config) :
		ActiveCampaign(config,
			{ "address_add" },
			{ std::bind(&Address::addressAdd, this, std::placeholders::_1, std::placeholders::_2) })
	{
	}

	json addressAdd(const std::string & action, const json & data)
	{
		(void)data;
		std::string url = UrlHandler::makeUrlWithParameters(action, m_config, data);
		return nullptr;
	}

};

#endif
