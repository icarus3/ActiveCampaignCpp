# ActiveCampaignCpp

ActiveCampaign API wrapper in C++

Usage

	//You will need valid URL and token from ActiveCampaign. Once you have it create a Config object using it.
	std::shared_ptr<Config> config = std::make_shared<Config>("", "");

	auto ac = ActiveCampaignFactory::Create("List", config);

	const json postData = {
							{ "name" ,		"Dr Who" },
							{ "sender_name" ,	"Bleh Bleh" },
							{ "sender_zip" ,	"12345" },
							{ "sender_city",	"London" },
							{ "sender_addr1" ,	"raxacoricofallapatorius" },
							{ "sender_country", 	"UK" },
							{ "sender_url",		"http://a.b.com" },
							{ "sender_reminder",	"Please Subscribe" }
						};

	json result = ac->api("list_add", postData);
	//Check the return code from result here

	const json data =
	{
		{ "ids" , "all" }
	};

	result = ac->api("list_list", data);
