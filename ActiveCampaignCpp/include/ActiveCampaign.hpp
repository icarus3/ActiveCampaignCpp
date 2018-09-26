#ifndef ACTIVECAMPAIGN_HPP
#define ACTIVECAMPAIGN_HPP

#include <vector>

#include "json.hpp"

using json = nlohmann::json;

class ActiveCampaign
{
public:
	virtual json api(const std::string & action, const json & data = nullptr) = 0;
	virtual void getSupportedActions(std::vector<std::string> & actions) = 0;
	virtual ~ActiveCampaign() = default;
};

#endif