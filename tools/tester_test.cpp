/*
 * Tester_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "tester.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Tester)

BOOST_AUTO_TEST_CASE(SimpleTest) {
  Tools::Tester tester(2, 2);
  tester.CountPenalty(1);
  BOOST_CHECK_EQUAL(tester.penalty(), 0);
  tester.CountPenalty(2);
  BOOST_CHECK_EQUAL(tester.penalty(), 0);
  tester.CountPenalty(3);
  BOOST_CHECK_EQUAL(tester.penalty(), 1);
  tester.CountPenalty(5);
  BOOST_CHECK_EQUAL(tester.penalty(), 9);
}

BOOST_AUTO_TEST_SUITE_END()
