#ifndef ACTIVECAMPAIGN_HPP
#define ACTIVECAMPAIGN_HPP

#include "json.hpp"

using json = nlohmann::json;

class ActiveCampaign
{
public:
	virtual json api(const json & data = nullptr) = 0;
	virtual ~ActiveCampaign() = default;
};

#endif