#include <iostream>
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "ActiveCampaignFactory.hpp"
#include "curl/curl.h"

int main()
{

	auto acFactory = std::make_unique<ActiveCampaignFactory>(std::move(std::make_unique<Config>("")));
	auto ac = acFactory->makeActiveCampaign("account/view");
	ac->api();

	CURL *curl = curl_easy_init();
	if (curl) {
		char *output = curl_easy_escape(curl, "data to convert[1]", 18);
		if (output) {
			printf("Encoded: %s\n", output);
			curl_free(output);
		}
	}

	return 0;
}