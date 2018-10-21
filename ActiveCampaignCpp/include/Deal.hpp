#ifndef DEAL_HPP
#define DEAL_HPP

#include <iostream>
#include <string>
#include <functional>

#include "json.hpp"
#include "Config.hpp"
#include "ActiveCampaign.hpp"
#include "AutoRegister.hpp"


using json = nlohmann::json;

class Deal : public ActiveCampaign, public AutoRegister<Deal>
{

public:
	Deal(const std::shared_ptr<Config> & config) :
		ActiveCampaign(config,
			{	"deal_add", "deal_delete", "deal_edit", "deal_get", "deal_list", "deal_note_add",
				"deal_note_edit", "deal_pipeline_add", "deal_pipeline_delete", "deal_pipeline_edit",
				"deal_pipeline_list", "deal_stage_add", "deal_stage_delete", "deal_stage_edit",
				"deal_stage_list", "deal_task_add", "deal_task_edit", "deal_tasktype_add", "deal_tasktype_delete",
				"deal_tasktype_edit"
			},
			{	std::bind(&Deal::dealAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealGet, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealNoteAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealNoteEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealPipelineAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealPipelineDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealPipelineEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealPipelineList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealStageAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealStageDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealStageEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealStageList, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealTaskAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealTaskEdit, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealTasktypeAdd, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealTasktypeDelete, this, std::placeholders::_1, std::placeholders::_2),
				std::bind(&Deal::dealTasktypeEdit, this, std::placeholders::_1, std::placeholders::_2)
			})
	{
		(void)s_bRegistered;
	}

	static std::unique_ptr<ActiveCampaign> CreateMethod(const std::shared_ptr<Config> & config)
	{
		return std::make_unique<Deal>(config);
	}

	static std::string GetFactoryName()
	{
		return "Deal";
	}

	json dealAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealDelete(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealGet(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json dealNoteAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealNoteEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealPipelineAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealPipelineDelete(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealPipelineEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealPipelineList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json dealStageAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealStageDelete(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealStageEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealStageList(const std::string & action, const json & data)
	{
		return get(action, data);
	}

	json dealTaskAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealTaskEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealTasktypeAdd(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealTasktypeDelete(const std::string & action, const json & data)
	{
		return post(action, data);
	}

	json dealTasktypeEdit(const std::string & action, const json & data)
	{
		return post(action, data);
	}
};

#endif
