#include "result_collector_builder.h"

namespace Base {

void ResultCollectorBuilder::SetConfig(Configuration config) {
  actual_config_ = config;
}

shared_ptr<ResultCollector> ResultCollectorBuilder::GenerateResultCollector() {

  shared_ptr<DataProvider> data_provider_ptr = GenerateDataProvider(
      actual_config_.GetDataInputMethod(), actual_config_.GetDataInputFile());

  shared_ptr<DataOutput> data_output_ptr = GenerateDataOutput(
      actual_config_.GetDataOutputMethod(), actual_config_.GetDataOutputFile());

  shared_ptr<DataCollector> data_collector_ptr = GenerateDataCollector(
      data_provider_ptr, data_output_ptr);

  shared_ptr<Tools::Judge> judge_ptr = GenerateJudge(
      actual_config_.GetJudgeSelection(),
      actual_config_.GetJudgeFreePositionRange(),
      actual_config_.GetJudgeSmallPenaltyPositionRange());

  shared_ptr<JudgeCollector> judge_collector_ptr = GenerateJudgeCollector(
      judge_ptr);

  ResultCollector* new_result_collector = new ResultCollector(
      data_collector_ptr, judge_collector_ptr);

  shared_ptr<ResultCollector> result_collector_ptr(new_result_collector);

  return result_collector_ptr;

}

shared_ptr<DataProvider> ResultCollectorBuilder::GenerateDataProvider(
    Configuration::DataProvider data_input, string file_path) {

  DataProvider* new_data_provider;

  switch (data_input) {

    case Configuration::DataProvider::ConsoleDataInput:
      break;  //TODO ConsoleDataInput !!

    case Configuration::DataProvider::FileDataInput:
      new_data_provider = new FileDataProvider(file_path);
      break;

    default:
      break;
  }

  shared_ptr<DataProvider> data_provider_ptr(new_data_provider);
  return data_provider_ptr;
}

shared_ptr<DataOutput> ResultCollectorBuilder::GenerateDataOutput(
    Configuration::DataOutput data_output, string file_path) {

  DataOutput* new_data_output;

  switch (data_output) {

    case Configuration::DataOutput::CSVConsoleDataOutput:
      new_data_output = new CsvDataOutput();
      break;

    case Configuration::DataOutput::CSVFileDataOoutput:
      new_data_output = new CsvFileDataOutput(file_path);
      break;

    default:
      break;
  }

  shared_ptr<DataOutput> data_output_ptr(new_data_output);
  return data_output_ptr;
}

shared_ptr<DataCollector> ResultCollectorBuilder::GenerateDataCollector(
    shared_ptr<DataProvider> data_provider,
    shared_ptr<DataOutput> data_output) {

  DataCollector* new_data_collector = new DataCollector(data_provider,
                                                        data_output);
  shared_ptr<DataCollector> data_collector_ptr = shared_ptr<DataCollector>(
      new_data_collector);

  return data_collector_ptr;
}

shared_ptr<Tools::Judge> ResultCollectorBuilder::GenerateJudge(
    Configuration::JudgeSelection selected_judge, int free_position_range,
    int small_penalty_range) {

  shared_ptr<Tools::Judge> new_judge;

  switch (actual_config_.GetJudgeSelection()) {
    case Configuration::JudgeSelection::Tester: {
      new_judge = std::make_shared<Tools::Tester>(free_position_range, small_penalty_range);
      break;
    }
    default:
      break;

  }
  return new_judge;
}

shared_ptr<JudgeCollector> ResultCollectorBuilder::GenerateJudgeCollector(
    shared_ptr<Tools::Judge> judge_ptr) {
  JudgeCollector* new_judge_collector = new JudgeCollector(judge_ptr);
  shared_ptr<JudgeCollector> judge_collector_ptr(new_judge_collector);
  vector<shared_ptr<Algorithms::Algorithm> > available_algorithms =
      actual_config_.algorithm();
  vector<shared_ptr<Algorithms::Algorithm> >::iterator algorithms_iterator;
  for (algorithms_iterator = available_algorithms.begin();
      algorithms_iterator != available_algorithms.end();
      algorithms_iterator++) {
    judge_collector_ptr->AddAlgorithm(*algorithms_iterator);
  }
  return judge_collector_ptr;
}

}
/* namespace Base */

