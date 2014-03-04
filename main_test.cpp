/*
 * main_test.cpp
 *
 *  Created on: 16 gru 2013
 *      Author: kuba
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include<memory>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Headers/DataManagment.h"
#include "Headers/Tools.h"

using std::string;
using std::stringstream;
using std::cout;

using namespace Base;
using namespace std;

BOOST_AUTO_TEST_SUITE(mainSuite)

BOOST_AUTO_TEST_CASE(True_test) {
  int step_size = 10;

  string path = "/dane/dane0.18.sort"; //ABSOLUTE PATH!!
  int learn_runs = 0;
  int test_runs = 1000;

  FileDataProvider fdp(path);
  DataCollector dc(fdp);
  Tools::ProcessorFactory* proc_fact = new Tools::TreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::MTFProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  proc_fact = new Tools::RandomTreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(proc_fact));

  dc.RunTurns(learn_runs, true);
  vector<pair<string, int> > results;
  stringstream ss;
  for (int i = 0; i < test_runs / step_size; i++) {
    dc.RunTurns(step_size);
    results = dc.GetResultsSum();
    ss << i * step_size << " ";
    for (vector<pair<string, int> >::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      ss << (*results_iter).first << " " << (*results_iter).second << " ";
    }
    BOOST_TEST_MESSAGE(ss.str());
  }
  int rest = test_runs - (test_runs / step_size) * step_size;
  if (rest > 0) {
    dc.RunTurns(rest);
    for (vector<pair<string, int> >::iterator results_iter = results.begin();
        results_iter != results.end(); results_iter++) {
      BOOST_TEST_MESSAGE((*results_iter).first << " " << (*results_iter).second << " ");
    }
    //cout << "\n";
  }
}

BOOST_AUTO_TEST_SUITE_END()

