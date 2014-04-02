/*
 * element_test.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: kuba
 */

#include "simple_element.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(elements_test)

// Test to check if difference of SimpleElement objects is measured correctly
BOOST_AUTO_TEST_CASE(SimpleElement_diff) {

  Base::SimpleElement s_element1(1), s_element2(2);

  Base::Element& element1 = s_element1;
  Base::Element& element2 = s_element2;

  element1.Notify();
  element1.Notify();
  element2.Notify();

  //Check difference between SimpleElements
  BOOST_CHECK_CLOSE(element1.Difference(element2), 0.33333333333, 0.01);
  BOOST_CHECK_CLOSE(element2.Difference(element1), -0.33333333333, 0.01);
  //Check equality between the same elements
  BOOST_CHECK_EQUAL(element1.Difference(element1),
                    element2.Difference(element2));
}

BOOST_AUTO_TEST_SUITE_END()
