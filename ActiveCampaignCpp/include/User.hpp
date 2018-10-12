#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class User : public ActiveCampaign, public AutoRegister<User>
{

public:
	User(const Config * config) :
		ActiveCampaign(config,
			{	"user_add", "user_delete", "user_delete_list", "user_edit",
				"user_list", "user_me", "user_view", "user_view_email", "user_view_username"
			},
			{	std::bind(&User::userAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userMe, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userView, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userViewEmail, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&User::userViewUsername, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const Config * config)
	{
		return std::make_unique<User>(config);
	}

	static std::string GetFactoryName()
	{
		return "User";
	}

	json userAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json userDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json userList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userMe(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userView(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userViewEmail(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json userViewUsername(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif
