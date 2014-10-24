#pragma once

#include "../../headers/algorithms.h"
#include "../../headers/controller.h"
#include "../../headers/tools.h"

#include "result_collector.h"
#include "data_collector.h"
#include "judge_collector.h"

#include "../data_outputs.h"
#include "../data_providers.h"

#include <memory>

using std::shared_ptr;

namespace Base {

class ResultCollectorBuilder {
 public:

  void SetConfig(Configuration config);

  shared_ptr<Base::ResultCollector> GenerateResultCollector();

 private:
  shared_ptr<DataProvider> GenerateDataProvider(
      Configuration::DataProvider data_input, string file_path);
  shared_ptr<DataOutput> GenerateDataOutput(
      Configuration::DataOutput data_output, string file_path);
  shared_ptr<DataCollector> GenerateDataCollector(
      shared_ptr<DataProvider> data_provider,
      shared_ptr<DataOutput> data_output);

  shared_ptr<Tools::Judge> GenerateJudge(
      Configuration::JudgeSelection selected_judge, int free_position_range,
      int small_penalty_range);

  shared_ptr<JudgeCollector> GenerateJudgeCollector(
      shared_ptr<Tools::Judge> judge_ptr);

  Configuration actual_config_;

};

} /* namespace Base */
