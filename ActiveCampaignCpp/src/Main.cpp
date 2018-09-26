#include <iostream>
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "ActiveCampaignFactory.hpp"


int main()
{
	std::unique_ptr<Config> config = std::make_unique<Config>(
		"",
		"");

	auto acFactory = std::make_unique<ActiveCampaignFactory>(config.get());
	auto ac = acFactory->makeActiveCampaign("account");

	json t =
	{
		{ "p[1]", 1},
		{ "test", "1"}
	};

	ac->api("account_view", t);

	return 0;
}