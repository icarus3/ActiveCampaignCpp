﻿#include <iostream>
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "ActiveCampaignFactory.hpp"

int main()
{
	//std::unique_ptr<Config> config = std::make_unique<Config>("", "");
	//auto ac = ActiveCampaignFactory::Create("List", config.get());

/*
	const json postData = {
				{ "name" ,		"Dr Who" },
				{ "sender_name" ,	"Bleh Bleh" },
				{ "sender_zip" ,	"12345" },
				{ "sender_city",	"London" },
				{ "sender_addr1" ,	"raxacoricofallapatorius" },
				{ "sender_country", 	"UK" },
				{ "sender_url",		"http://a.b.com" },
				{ "sender_reminder",	"Please subscribe" }
			};

	ac->api("list_add", postData);

	const json data = {
		{ "ids" , "all" }
	};

	ac->api("list_list", data);
*/


	return 0;
}
