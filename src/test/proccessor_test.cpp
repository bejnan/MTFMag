/*
 * Proccessor_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "../headers/controller.h"
#include "../headers/algorithms.h"
#include "../headers/elements.h"
#include "../headers/exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

//TODO test more processors
BOOST_AUTO_TEST_SUITE(Proccessor)

//Test to check TreeProcessor correctness
BOOST_AUTO_TEST_CASE(TreeProcessorProceedTest) {
  Algorithms::Algorithm* algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);

  Tools::ProcessorFactory factory(algorithm_ptr,judge_ptr);

  shared_ptr<Tools::Processor> processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty());
  }
}

//Test to check RandomTreeProcessor correctness
BOOST_AUTO_TEST_CASE(RandomTreeProcessorProceedTest) {
  Algorithms::Algorithm* algorithm = new Algorithms::RandomTreeRoot(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);

  Tools::ProcessorFactory factory(algorithm_ptr,judge_ptr);

  shared_ptr<Tools::Processor> processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty());
  }
}

//Test to check MTFMatrixProcessor correctness
BOOST_AUTO_TEST_CASE(MTFMatrixProcessorProceedTest) {
  Algorithms::Algorithm* algorithm = new Algorithms::MTFMatrix(
      Base::SimpleElement::GetPrototype());
  Tools::Judge* judge = new Tools::Tester(20, 20);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(algorithm);
  shared_ptr<Tools::Judge> judge_ptr(judge);

  Tools::ProcessorFactory factory(algorithm_ptr,judge_ptr);

  shared_ptr<Tools::Processor> processor = factory.GenerateProcessor(0);
  for (int i = 0; i < 20; i++) {
    processor->Proceed(i);
  }
  // all elements should fill first 20 positions
  BOOST_CHECK_EQUAL(processor->GetPenalty(), 0);

  // shows increase of penalty
  for (int i = 20; i >= 0; i--) {
    processor->Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor->GetPenalty());
  }
}

BOOST_AUTO_TEST_SUITE_END()
