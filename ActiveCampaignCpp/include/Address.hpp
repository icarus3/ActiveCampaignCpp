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
			{	"address_add", "address_delete", "address_delete_group", "address_delete_list",
				"address_edit", "address_list", "address_view"
			},
			{	std::bind(&Address::addressAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Address::addressDelete, this, std::placeholders::_1, std::placeholders::_2), 
				std::bind(&Address::addressDeleteGroup, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Address::addressDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Address::addressEdit, this, std::placeholders::_1, std::placeholders::_2), 
				std::bind(&Address::addressList, this, std::placeholders::_1, std::placeholders::_2), 
				std::bind(&Address::addressView, this, std::placeholders::_1, std::placeholders::_2) 
			})
	{
	}

	json addressAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json addressDelete(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json addressDeleteGroup(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json addressDeleteList(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json addressEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json addressList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json addressView(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
