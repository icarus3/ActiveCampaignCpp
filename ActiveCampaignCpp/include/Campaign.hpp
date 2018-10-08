#ifndef CAMPAIGN_HPP
#define CAMPAIGN_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"

using json = nlohmann::json;

class Campaign : public ActiveCampaign
{

public:
	Campaign(const Config * config) :
		ActiveCampaign(config,
			{	"campaign_create", "campaign_delete", "campaign_delete_list", "campaign_list",
				"campaign_paginator", "campaign_report_bounce_list", "campaign_report_bounce_totals",
				"campaign_report_forward_list", "campaign_report_forward_totals",
				"campaign_report_link_list", "campaign_report_link_totals", "campaign_report_open_list",
				"campaign_report_open_totals", "campaign_report_totals", "campaign_report_unopen_list",
				"campaign_report_unsubscription_list", "campaign_report_unsubscription_totals",
				"campaign_send", "campaign_status"
			},
			{	std::bind(&Campaign::campaignCreate, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignDeleteList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignPaginator, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportBounceList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportBounceTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportForwardList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportForwardTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportLinkList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportLinkTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportOpenList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportOpenTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportUnopenList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportUnsubscriptionList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignReportUnsubscriptionTotals, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignSend, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Campaign::campaignStatus, this, std::placeholders::_1, std::placeholders::_2),
			})
	{
	}

	json campaignCreate(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json campaignDelete(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignDeleteList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignPaginator(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportBounceList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportBounceTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportForwardList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportForwardTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportLinkList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportLinkTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportOpenList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportOpenTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportUnopenList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportUnsubscriptionList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignReportUnsubscriptionTotals(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignSend(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json campaignStatus(const std::string & action, const json & data)
	{
		return get(action, data);
	}
};


#endif
