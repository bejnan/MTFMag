#pragma once

#include "../../headers/algorithms.h"
#include "../../headers/controller.h"
#include "../../headers/tools.h"

#include "../../headers/data_managment.h"
#include "../analysis_runner.h"

namespace control {

using namespace Base;
class ObjectsBuilder {
public:

	ObjectsBuilder(Base::Configuration configuration);
	void Build();
	AnalysisRunner getAnalysisRunner();

private:
	Base::Configuration build_config;

	shared_ptr<DataProvider> GenerateDataProvider(string file_path);
	shared_ptr<DataOutput> GenerateDataOutput(string file_path);
	shared_ptr<DataCollector> GenerateDataCollector(shared_ptr<DataProvider> data_provider,
			shared_ptr<DataOutput> data_output);

	shared_ptr<Tools::Judge> GenerateJudge(int free_position_range, int small_penalty_range);

	shared_ptr<JudgeCollector> GenerateJudgeCollector(shared_ptr<Tools::Judge> judge_ptr);

};

} // namespace control
