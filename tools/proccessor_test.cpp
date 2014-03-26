/*
 * Proccessor_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "processor.h"
#include "tree_proccessor.h"
#include "tree_processor_factory.h"
#include "../headers/exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

//TODO test more processors
BOOST_AUTO_TEST_SUITE(Proccessor)

BOOST_AUTO_TEST_CASE(ProceedTest1) {
  Tools::TreeProcessorFactory factory;
  shared_ptr<Tools::Processor>  processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 21; i++) {
    processor->Proceed(i);
  }
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty() );
  }
}

BOOST_AUTO_TEST_SUITE_END()
