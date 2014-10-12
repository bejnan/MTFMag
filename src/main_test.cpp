/*
 * main_test.cpp
 *
 *  Created on: 16 gru 2013
 *      Author: Jakub Banaszewski
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>
#include "headers/data_managment.h"
#include "headers/tools.h"
#include "headers/algorithms.h"

using std::string;
using std::stringstream;
using std::cout;
using std::shared_ptr;

using namespace Base;
using namespace std;

BOOST_AUTO_TEST_SUITE(mainSuite)

BOOST_AUTO_TEST_CASE(True_test) {
/*  int step_size = 100;

  int argc = boost::unit_test::framework::master_test_suite().argc;
  char ** argv = boost::unit_test::framework::master_test_suite().argv;
  string path;
  if (argc > 1) {
    path = argv[1];
  } else {
    path = "/dane/dane0.18.sort";  //ABSOLUTE PATH!!
  }
  int learn_runs = 0;
  int test_runs = 1000;

  Base::Configuration configuration;

  configuration.SetElementPrototype(SimpleElement::GetPrototype());

  configuration.SetDataInputMethod(Configuration::DataProvider::FileDataInput);
  configuration.SetDataInputFile(path);
  configuration.SetDataOutputMethod(
      Configuration::DataOutput::CSVConsoleDataOutput);
  configuration.SetJudgeFreePositionRange(20);
  configuration.SetJudgeSmallPenaltyPositionRange(20);
  configuration.SetLearnTurns(learn_runs);
  configuration.SetRunTurns(test_runs);

  configuration.AddAlgorithm(Algorithms::TreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::RandomTreeRoot::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MoveToFront::AlgorithmName());
  configuration.AddAlgorithm(Algorithms::MTFMatrix::AlgorithmName());

  Base::ResultCollectorBuilder result_builder;

  result_builder.SetConfig(configuration);

  shared_ptr<Base::ResultCollector> result_collector = result_builder
      .GenerateResultCollector();
  result_collector->SetTurns(learn_runs, test_runs);
  result_collector->SetResultFrequency(step_size);

  result_collector->Run();

  Base::Database::GetInstance().ClearDatabase();
  */
}

BOOST_AUTO_TEST_SUITE_END()

