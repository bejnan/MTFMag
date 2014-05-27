/*
 * DataCollector_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "data_collector.h"
#include "../file_data_provider.h"
#include "../data_outputs.h"

#include "../../headers/tools.h"
#include "../../headers/exceptions.h"
#include "../../headers/algorithms.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

int RunTurnsAndReturnPenalty(int turns, Base::DataCollector& data_collector) {
  data_collector.RunTurns(turns);
  vector<int> results = data_collector.GetResultsSum();
  int result = results.front();
  return result;
}

BOOST_AUTO_TEST_SUITE(DataCollector)

//Test cooperation between DataCollector object and TreeProcessor
BOOST_AUTO_TEST_CASE(DataCollectorTreeProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  shared_ptr<Base::DataOutputBuilder> data_output_builder =
      Base::DataOutputBuilder::GetInstance();
  data_output_builder->SetCsvOutputFormat('|');
  Base::DataCollector data_collector(file_data_provider,
                                     data_output_builder->Generate());
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory* processor = new Tools::ProcessorFactory(
      algorithm_ptr, judge_ptr);
  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);
  //test
  int result = RunTurnsAndReturnPenalty(22, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
  Base::Database::GetInstance().ClearDatabase();
}

//Test cooperation between DataCollector object and MTFProcessor
BOOST_AUTO_TEST_CASE(DataCollectorMTFProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  shared_ptr<Base::DataOutputBuilder> data_output_builder =
      Base::DataOutputBuilder::GetInstance();
  data_output_builder->SetCsvOutputFormat('|');
  Base::DataCollector data_collector(file_data_provider,
                                     data_output_builder->Generate());
  Algorithms::Algorithm* algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory* processor = new Tools::ProcessorFactory(
      algorithm_ptr, judge_ptr);

  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);

  //test
  int result = RunTurnsAndReturnPenalty(23, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
  Base::Database::GetInstance().ClearDatabase();
}

//Test cooperation between DataCollector object and MTFMatrixProcessor
BOOST_AUTO_TEST_CASE(DataCollectorMTFMatrixProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  shared_ptr<Base::DataOutputBuilder> data_output_builder =
      Base::DataOutputBuilder::GetInstance();
  data_output_builder->SetCsvOutputFormat('|');
  Base::DataCollector data_collector(file_data_provider,
                                     data_output_builder->Generate());

  Algorithms::Algorithm* algorithm = new Algorithms::MTFMatrix(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory* processor = new Tools::ProcessorFactory(
      algorithm_ptr, judge_ptr);

  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);

  //test
  int result = RunTurnsAndReturnPenalty(23, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
  Base::Database::GetInstance().ClearDatabase();
}

BOOST_AUTO_TEST_SUITE_END()
