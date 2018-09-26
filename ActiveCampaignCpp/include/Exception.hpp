#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

class Exception : public std::exception
{
protected:
	std::string m_msg;

public:
	explicit Exception(const char* message) : m_msg(message)
	{
	}

	explicit Exception(const std::string& message) : m_msg(message)
	{}

	virtual ~Exception() throw ()
	{
	}

	virtual const char* what() const throw ()
	{
		return m_msg.c_str();
	}
};

#endif
