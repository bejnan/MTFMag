/*
 * Proccessor_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "processor.h"
#include "processor_factories.h"
#include "../headers/exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

//TODO test more processors
BOOST_AUTO_TEST_SUITE(Proccessor)

//Test to check TreeProcessor correctness
BOOST_AUTO_TEST_CASE(TreeProcessorProceedTest) {
  Tools::TreeProcessorFactory factory;
  shared_ptr<Tools::Processor>  processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty() );
  }
}

//Test to check RandomTreeProcessor correctness
BOOST_AUTO_TEST_CASE(RandomTreeProcessorProceedTest) {
  Tools::RandomTreeProcessorFactory factory;
  shared_ptr<Tools::Processor>  processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty() );
  }
}

//Test to check MTFMatrixProcessor correctness
BOOST_AUTO_TEST_CASE(MTFMatrixProcessorProceedTest) {
  Tools::MatrixMTFProcessorFactory factory;
  shared_ptr<Tools::Processor>  processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty() );
  }
}

BOOST_AUTO_TEST_SUITE_END()
