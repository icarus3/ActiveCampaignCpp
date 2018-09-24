#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "json.hpp"
#include "Httpops.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Account : public ActiveCampaign
{
	std::string action;
	std::unique_ptr<HttpOps> httpOps;
public:
	Account(const std::string & action,
		std::unique_ptr<HttpOps> httpOps)
		:action(action), httpOps(std::move(httpOps))
	{
	}

	json api(const json & data)
	{
		return httpOps->sendData(data);
	}
};

#endif