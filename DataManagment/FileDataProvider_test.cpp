/*
 * FileDataProvider_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "FileDataProvider.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FileDataProvider)

BOOST_AUTO_TEST_CASE(SimpleFile) {
  Base::FileDataProvider fdata("test_input.txt");
  Base::DataProvider& data = fdata;
  data.GoToNextLine();
  BOOST_CHECK_EQUAL(data.GetActualLine(),"18 1000000 1 10\n");
  BOOST_CHECK_EQUAL(data.GetLineBefore(),"");
  data.GoToNextLine();
  BOOST_CHECK_EQUAL(data.GetActualLine(),"18 1000000 2 10\n");
  BOOST_CHECK_EQUAL(data.GetLineBefore(),"18 1000000 1 10\n");

}

BOOST_AUTO_TEST_SUITE_END()
