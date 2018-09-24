#ifndef HTTPOPSFACTORY_HPP
#define HTTPOPSFACTORY_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "HttpOps.hpp"

class HttpOpsFactory
{
	std::map<std::string, std::function<std::unique_ptr<HttpOps>()>> m_factories;

public:

	HttpOpsFactory()
	{
		m_factories["GET"] = [] {
			return std::make_unique<HttpGetOps>();
		};

		m_factories["POST"] = [] {
			return std::make_unique<HttpPostOps>();
		};
	}

	std::unique_ptr<HttpOps> makeHttpOps(const std::string& name)
	{
		return m_factories[name]();
	}
};

#endif
