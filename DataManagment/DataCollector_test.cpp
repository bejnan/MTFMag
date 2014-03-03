/*
 * DataCollector_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "DataCollector.h"
#include "FileDataProvider.h"

#include "../Headers/Tools.h"
#include "../Headers/Exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

BOOST_AUTO_TEST_SUITE(DataCollector)

BOOST_AUTO_TEST_CASE(DataCollectorTreeProcessor) {
  Base::FileDataProvider fdp("test_input.txt");
  Base::DataCollector dc(fdp);
  Tools::ProcessorFactory* processor = new Tools::TreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(processor));
  dc.RunTurns(22);
  vector<pair<string, int> > results = dc.GetResult(0);
  vector<pair<string, int> >::iterator result_iter;
  for (result_iter = results.begin(); result_iter != results.end();
      result_iter++) {
    BOOST_TEST_MESSAGE((*result_iter).first << " " << (*result_iter).second);
  }
  results = dc.GetResultsSum();
}

BOOST_AUTO_TEST_CASE(DataCollectorTreeProcessor2) {
  Base::FileDataProvider fdp("test_input.txt");
  Base::DataCollector dc(fdp);
  Tools::ProcessorFactory* processor = new Tools::TreeProcessorFactory();
  dc.AddProccessorFactory(shared_ptr<Tools::ProcessorFactory>(processor));
  dc.RunTurns(44);
  vector<pair<string, int> > results;
  vector<pair<string, int> >::iterator result_iter;
  for (int i = 0; i < 13; i++) {
    results = dc.GetResult(i);
    for (result_iter = results.begin(); result_iter != results.end();
        result_iter++) {
      BOOST_TEST_MESSAGE(i << " " << (*result_iter).first << " " << (*result_iter).second);
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
