#include <functional>

#include "gtest/gtest.h"

#include "Config.hpp"
#include "UrlHandler.hpp"
#include "ActiveCampaign.hpp"

#include "json.hpp"

using json = nlohmann::json;

TEST(JsonConstructionTest, NonNestedJsonConstruction)
{
	json postData = {
						{ "name",		 "Dr Who" },
						{ "sender_name", "Bleh Bleh" },
						{ "sender_zip",	 12345 }
					};

	EXPECT_EQ("Dr Who", postData["name"]);
	EXPECT_EQ("Bleh Bleh", postData["sender_name"]);
	EXPECT_EQ(12345, postData["sender_zip"]);
}

TEST(ConfigTest, ConfirmConfigParameters)
{
	std::unique_ptr<Config> config = std::make_unique<Config>("a", "b");
	EXPECT_EQ("a", config->getUrl());
	EXPECT_EQ("b", config->getApiKey());
	EXPECT_EQ("json", config->getFormat());
}

TEST(UrlHandlerTest, CheckReturnValuesOfURL)
{
	std::unique_ptr<Config> config = std::make_unique<Config>("http://a.b.com", "xyz");
	json data = {
					{ "name",		 "Dr Who" },
					{ "sender_name", "Bleh Bleh" },
					{ "sender_zip",	 12345 }
				};

	std::string url = UrlHandler::makeUrl("test_action", config.get());
	std::string expectedUrl = "http://a.b.com/admin/api.php?api_action=test_action&api_output=json&api_key=xyz";
	EXPECT_EQ(url, expectedUrl);

	std::string params = UrlHandler::makeParameters(config.get(), data);
	std::string expectedParams = "name=Dr%20Who&sender_name=Bleh%20Bleh&sender_zip=12345";
	EXPECT_EQ(params, expectedParams);

	std::string urlWithParams = UrlHandler::makeUrlWithParameters("test_action", config.get(), data);
	std::string expectedurlWithParams = "http://a.b.com/admin/api.php?api_action=test_action&api_output=json&api_key=xyz&name=Dr%20Who&sender_name=Bleh%20Bleh&sender_zip=12345";
	EXPECT_EQ(urlWithParams, expectedurlWithParams);
}

TEST(ActiveCampaignTest, GetSupportedActionsAndAPI)
{
	std::unique_ptr<Config> config = std::make_unique<Config>("http://a.b.com", "xyz");
	std::function < json(const std::string & action, const json & data) > handler = [](const std::string & action, const json & data) { json res = { {"ret", 0} }; return res; };

	auto actions = { std::string("test_action") };
	auto handlers = { handler };
	std::unique_ptr<ActiveCampaign> ac = std::make_unique<ActiveCampaign>( config.get(), actions, handlers);

	std::vector<std::string> res;
	ac->getSupportedActions(res);

	ASSERT_EQ(res.size(), 1);
	EXPECT_EQ(res[0], "test_action");
	
	json jsonResponse = ac->api("test_action");
	ASSERT_EQ(jsonResponse["ret"], 0);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}