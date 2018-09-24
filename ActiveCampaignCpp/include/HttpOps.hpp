#ifndef HTTPOPS_HPP
#define HTTPOPS_HPP

#include "json.hpp"
using json = nlohmann::json;

class HttpOps
{
public:
	virtual json sendData(const json& data = nullptr) = 0;
};

class HttpGetOps : public HttpOps
{
public:
	json sendData(const json& data) override
	{
		//lib curl logic to do http get
		return nullptr;
	}
};

class HttpPostOps : public HttpOps
{
public:
	json sendData(const json& data) override
	{
		//lib curl logic to do http post
		return nullptr;
	}
};

#endif