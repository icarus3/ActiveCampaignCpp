#ifndef HTTPOPSFACTORY_HPP
#define HTTPOPSFACTORY_HPP

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "HttpOps.hpp"

class HttpOpsFactory
{
	std::map<std::string, std::function<std::unique_ptr<HttpOps>()>> factories;

public:

	HttpOpsFactory()
	{
		factories["GET"] = [] {
			return std::make_unique<HttpGetOps>();
		};

		factories["POST"] = [] {
			return std::make_unique<HttpPostOps>();
		};
	}

	std::unique_ptr<HttpOps> makeHttpOps(const std::string& name)
	{
		return factories[name]();
	}
};

#endif
