#ifndef IACTIVECAMPAIGN_HPP
#define IACTIVECAMPAIGN_HPP
#include <vector>

#include "json.hpp"

using json = nlohmann::json;

class IActiveCampaign
{
private:
	virtual json api(const std::string & action, const json & data = nullptr) = 0;
	virtual void getSupportedActions(std::vector<std::string> & actions) = 0;

public:
	virtual ~IActiveCampaign() = default;
};

#endif
