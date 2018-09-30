#ifndef CURL_HPP
#define CURL_HPP

#include "curl/curl.h"
#include "Exception.hpp"

class LibCurl
{
	CURL * m_curl;

	LibCurl()
	{
		curl_global_init(CURL_GLOBAL_DEFAULT);
		m_curl = curl_easy_init();
		if (!m_curl)
		{
			curl_global_cleanup();
			throw new Exception("Unable to initialize curl");
		}
	}

public:

	~LibCurl()
	{
		curl_easy_cleanup(m_curl);
		curl_global_cleanup();
	}

	CURL * getCurl()
	{
		return m_curl;
	}

	static LibCurl * getLibCurlImpl()
	{
		static LibCurl * libCurl = NULL;
		if (!libCurl)
		{
			libCurl = new LibCurl();
		}
		return libCurl;
	}
};

#endif

