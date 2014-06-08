#include "result_collector_builder.h"
#include "data_collector.h"
#include "judge_collector.h"

#include "../database.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

using namespace Base;

// Method building standard configurations
void BuildAndRun() {
  Base::Configuration configuration;

  configuration.SetElementPrototype(SimpleElement::GetPrototype());

  configuration.SetDataInputMethod(Configuration::DataInput::FileDataInput);
  configuration.SetDataInputFile("test_input.txt");
  configuration.SetDataOutputMethod(
      Configuration::DataOutput::CSVConsoleDataOutput);
  configuration.SetJudgeFreePositionRange(2);
  configuration.SetJudgeSmallPenaltyPositionRange(2);
  configuration.SetLearnTurns(10);
  configuration.SetRunTurns(10);

  configuration.AddAlgorithm(Algorithms::TreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::RandomTreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MoveToFront::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MTFMatrix::AlgorithmName());

  Base::ResultCollectorBuilder result_builder;

  result_builder.SetConfig(configuration);

  shared_ptr<Base::ResultCollector> result_collector = result_builder
      .GenerateResultCollector();

  result_collector->Run();

  Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_SUITE(ResultCollectorTest)

//Tests if standard configuration is loaded and run's propertly
BOOST_AUTO_TEST_CASE(ResultCollectionBuild) {
  BOOST_CHECK_NO_THROW(BuildAndRun());
}

BOOST_AUTO_TEST_CASE(ResultCollectionCorrectness) {
  //initialization

  DataProvider* file_data_provider = new FileDataProvider("test_input.txt");
  shared_ptr<DataProvider> data_provider_ptr(file_data_provider);
  DataOutput* console_data_output = new CsvDataOutput('|');
  shared_ptr<DataOutput> data_output_ptr(console_data_output);
  DataCollector* new_data_collector = new DataCollector(data_provider_ptr,
                                                        data_output_ptr);
  shared_ptr<DataCollector> data_collector_ptr(new_data_collector);

  Tools::Judge* new_judge = new Tools::Tester(2, 2);
  shared_ptr<Tools::Judge> judge_ptr(new_judge);
  JudgeCollector* new_judge_collector = new JudgeCollector(judge_ptr);
  shared_ptr<JudgeCollector> judge_collector_ptr(new_judge_collector);

  Algorithms::Algorithm* new_algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);

  judge_collector_ptr->AddAlgorithm(algorithm_ptr);

  ResultCollector result_collector(data_collector_ptr, judge_collector_ptr);

  result_collector.SetTurns(0, 3);
  result_collector.Run();

  Base::Result result = judge_collector_ptr->GetResult(10)->front();

  BOOST_CHECK_EQUAL(result.GetOverallPenalty(), 1);

  Base::Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_CASE(ResultCollectionSetTurnTest) {
  //initialization

  DataProvider* file_data_provider = new FileDataProvider("test_input.txt");
  shared_ptr<DataProvider> data_provider_ptr(file_data_provider);
  DataOutput* console_data_output = new CsvDataOutput('|');
  shared_ptr<DataOutput> data_output_ptr(console_data_output);
  DataCollector* new_data_collector = new DataCollector(data_provider_ptr,
                                                        data_output_ptr);
  shared_ptr<DataCollector> data_collector_ptr(new_data_collector);

  Tools::Judge* new_judge = new Tools::Tester(2, 2);
  shared_ptr<Tools::Judge> judge_ptr(new_judge);
  JudgeCollector* new_judge_collector = new JudgeCollector(judge_ptr);
  shared_ptr<JudgeCollector> judge_collector_ptr(new_judge_collector);

  Algorithms::Algorithm* new_algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);

  judge_collector_ptr->AddAlgorithm(algorithm_ptr);

  ResultCollector result_collector(data_collector_ptr, judge_collector_ptr);

  result_collector.SetTurns(3, 0);

  //test
  result_collector.Run();

  Base::Result result = judge_collector_ptr->GetResult(10)->front();

  BOOST_CHECK_EQUAL(result.GetOverallPenalty(), 0);

  Base::Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_SUITE_END()
