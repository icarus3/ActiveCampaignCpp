#ifndef ACTIVECAMPAIGN_HPP
#define ACTIVECAMPAIGN_HPP

#include <vector>
#include <string>
#include <functional>

#include "json.hpp"
#include "IActiveCampaign.hpp"
#include "UrlHandler.hpp"
#include "HttpOps.hpp"
#include "HttpOpsFactory.hpp"

using json = nlohmann::json;

class ActiveCampaign : public IActiveCampaign
{
	typedef std::function < json(const std::string & action, const json & data) > Handler;

	const std::vector< std::string > m_supportedActions;
	const std::vector< Handler > m_supportedActionsHandlers;

protected:
	const Config * m_config;

public:

	ActiveCampaign( const Config * config,
					std::initializer_list<std::string> supportedActions,
					std::initializer_list<Handler> supportedActionsHandlers ) :
		m_config(config),
		m_supportedActions( supportedActions ),
		m_supportedActionsHandlers( supportedActionsHandlers )
	{
	}

	json post(const std::string & action, const json & data) override
	{
		std::string url = UrlHandler::makeUrl(action, m_config);
		std::string parameters = UrlHandler::makeParameters(m_config, data);

		std::unique_ptr<HttpOps> httpPost = HttpOpsFactory().makeHttpOps("POST");
		return httpPost->sendData(url, parameters);
	}

	json get(const std::string & action, const json & data) override
	{
		std::string url = UrlHandler::makeUrlWithParameters(action, m_config, data);
		std::unique_ptr<HttpOps> httpGet = HttpOpsFactory().makeHttpOps("GET");
		return httpGet->sendData(url);
	}

	json api(const std::string & action, const json & data = {}) override
	{
		auto it = std::find(std::begin(m_supportedActions), std::end(m_supportedActions), action);
		if (it == std::end(m_supportedActions))
		{
			throw new Exception("Action:" + action + " not supported.");
		}

		Handler func = m_supportedActionsHandlers.at(it - std::begin(m_supportedActions));
		return func(action, data);
	}

	void getSupportedActions(std::vector<std::string> & actions) override
	{
		actions = m_supportedActions;
	}
};

#endif