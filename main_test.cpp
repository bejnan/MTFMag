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
  int step_size = 100;

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

  Base::FileDataProvider file_data_provider(path);
  shared_ptr<Base::DataOutputBuilder> data_output_builder =
      Base::DataOutputBuilder::GetInstance();
  data_output_builder->SetCsvOutputFormat('|');
  Base::DataCollector dc(file_data_provider, data_output_builder->Generate());
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);
  Tools::ProcessorFactory* tree_factory = new Tools::ProcessorFactory(
      algorithm_ptr, judge_ptr);

  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(tree_factory));

  algorithm = new Algorithms::MoveToFront(Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> mtf_algorithm_ptr(algorithm);
  Tools::ProcessorFactory* mtf_factory = new Tools::ProcessorFactory(
      mtf_algorithm_ptr, judge_ptr);
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(mtf_factory));

  algorithm = new Algorithms::RandomTreeRoot(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> random_tree_algorithm_ptr(algorithm);
  Tools::ProcessorFactory* random_tree_factory = new Tools::ProcessorFactory(
      random_tree_algorithm_ptr, judge_ptr);
  dc.AddProccessorFactory(
      shared_ptr<Tools::ProcessorFactory>(random_tree_factory));

  dc.RunTurns(learn_runs, true);
  vector<int> results;
  stringstream ss;

  for (int i = 0; i < test_runs / step_size; i++) {
    dc.RunTurns(step_size);
    results = dc.GetResultsSum();
    ss << i * step_size << " ";
    for (vector<int>::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      ss << (*results_iter) << "  ";
    }
    BOOST_TEST_MESSAGE(ss.str());
    ss.str("");
  }
  int rest = test_runs - (test_runs / step_size) * step_size;
  if (rest > 0) {
    dc.RunTurns(rest);
    for (vector<int>::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      ss << (*results_iter) << " ";
    }
    BOOST_TEST_MESSAGE(ss.str());
  }
}

BOOST_AUTO_TEST_SUITE_END()

