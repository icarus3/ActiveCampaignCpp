#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

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
		return post(action, data);
	}
};

#endif
