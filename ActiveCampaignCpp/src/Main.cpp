#include <iostream>
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "ActiveCampaignFactory.hpp"

int main()
{
	std::unique_ptr<Config> config = std::make_unique<Config>(
		"https://naktyarawal.api-us1.com",
		"ca71631b663cdadbdcda8daf5b952e196ba184803b02d097f3a530bf7000d319c7a4a299");

	auto acFactory = std::make_unique<ActiveCampaignFactory>(config.get());
	auto ac = acFactory->makeActiveCampaign("list");

	//ac->api("account_view");

	const json postData = {
		{ "name" ,			"Dr Who" },
		{ "sender_name" ,	"Bleh Bleh" },
		{ "sender_zip" ,	"12345" },
		{ "sender_city",	"London" },
		{ "sender_addr1" ,	"raxacoricofallapatorius" },
		{ "sender_country", "UK" },
		{ "sender_url",	"http://a.b.com" },
		{ "sender_reminder", "Please unsubscribe" }
	};

	ac->api("list_add", postData);

	return 0;
}