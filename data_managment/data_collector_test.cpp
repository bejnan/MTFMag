/*
 * DataCollector_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "data_collector.h"
#include "file_data_provider.h"

#include "../headers/tools.h"
#include "../headers/exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

int RunTurnsAndReturnPenalty(int turns, Base::DataCollector& data_collector) {
  data_collector.RunTurns(turns);
  vector<pair<string, int> > results = data_collector.GetResultsSum();
  int result = results.front().second;
  return result;
}

BOOST_AUTO_TEST_SUITE(DataCollector)

//Test cooperation between DataCollector object and TreeProcessor
BOOST_AUTO_TEST_CASE(DataCollectorTreeProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  Base::DataCollector data_collector(file_data_provider);
  Tools::ProcessorFactory* processor = new Tools::TreeProcessorFactory();
  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);
  //test
  int result = RunTurnsAndReturnPenalty(23, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
}

//Test cooperation between DataCollector object and MTFProcessor
BOOST_AUTO_TEST_CASE(DataCollectorMTFProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  Base::DataCollector data_collector(file_data_provider);
  Tools::ProcessorFactory* processor = new Tools::MTFProcessorFactory();
  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);

  //test
  int result = RunTurnsAndReturnPenalty(24, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
}

//Test cooperation between DataCollector object and MTFMatrixProcessor
BOOST_AUTO_TEST_CASE(DataCollectorMTFMatrixProcessor) {
  //initialization
  Base::FileDataProvider file_data_provider("test_input.txt");
  Base::DataCollector data_collector(file_data_provider);
  Tools::ProcessorFactory* processor = new Tools::MatrixMTFProcessorFactory(2);
  shared_ptr<Tools::ProcessorFactory> processors_shared_ptr(processor);
  data_collector.AddProccessorFactory(processors_shared_ptr);

  //test
  int result = RunTurnsAndReturnPenalty(23, data_collector);
  BOOST_CHECK_EQUAL(result, 1);
}

BOOST_AUTO_TEST_SUITE_END()
