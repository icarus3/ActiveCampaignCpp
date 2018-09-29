#ifndef ACTIVECAMPAIGN_HPP
#define ACTIVECAMPAIGN_HPP

#include <vector>
#include <vector>

#include "json.hpp"
#include "IActiveCampaign.hpp"

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
		m_config( config ),
		m_supportedActions( supportedActions ),
		m_supportedActionsHandlers( supportedActionsHandlers )
	{

	}

	json api(const std::string & action, const json & data = nullptr)
	{
		auto it = std::find(std::begin(m_supportedActions), std::end(m_supportedActions), action);
		if (it == std::end(m_supportedActions))
		{
			throw new Exception("Action:" + action + " not supported.");
		}

		Handler func = m_supportedActionsHandlers.at(it - std::begin(m_supportedActions));
		return func(action, data);
	}

	void getSupportedActions(std::vector<std::string> & actions)
	{
		actions = m_supportedActions;
	}
};

#endif