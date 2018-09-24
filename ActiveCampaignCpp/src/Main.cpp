#include <iostream>
#include "ActiveCampaign.hpp"
#include "ActiveCampaignFactory.hpp"

int main()
{
	std::unique_ptr<ActiveCampaign> ac = ActiveCampaignFactory().makeActiveCampaign("account/view");
	ac->api();

	return 0;
}