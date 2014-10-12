/*
 * result_collector_builder.h
 *
 *  Created on: May 29, 2014
 *      Author: kuba
 */

#ifndef RESULT_COLLECTOR_BUILDER_H_
#define RESULT_COLLECTOR_BUILDER_H_

#include "../../headers/algorithms.h"
#include "../../headers/controller.h"
#include "../../headers/tools.h"

#include "data_collector.h"
#include "judge_collector.h"
#include "result_collector.h"

#include "../data_outputs.h"
#include "../data_providers.h"

#include <memory>

using std::shared_ptr;

namespace Base {

class ResultCollectorBuilder {
 public:

  void SetConfig(Configuration config);

  shared_ptr<ResultCollector> GenerateResultCollector();

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

#endif /* RESULT_COLLECTOR_BUILDER_H_ */
