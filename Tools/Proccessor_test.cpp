/*
 * Proccessor_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Proccessor.h"
#include "../Headers/Exceptions.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

BOOST_AUTO_TEST_SUITE(Proccessor)

BOOST_AUTO_TEST_CASE(ProceedTest1) {
  Tools::Processor processor(0, "Test");
  for (int i = 0; i < 21; i++) {
    processor.Proceed(i);
  }
  BOOST_CHECK_EQUAL(processor.GetPenalty(), 0);
  for (int i = 20; i >= 0; i--) {
    processor.Proceed(i);
    BOOST_TEST_MESSAGE(i << " " << processor.GetPenalty() );
  }
}

BOOST_AUTO_TEST_SUITE_END()
