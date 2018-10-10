#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Form : public ActiveCampaign
{

public:
	Form(const Config * config) :
		ActiveCampaign(config,
			{	"form_getforms",
				"form_html"
			},
			{	std::bind(&Form::formGetforms, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Form::formHtml, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
	}

	json formGetforms(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json formHtml(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};

#endif