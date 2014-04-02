/*
 * FileDataProvider_test.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "file_data_provider.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FileDataProvider)

// Test to check if FileDataProvider reads input in correct way
BOOST_AUTO_TEST_CASE(SimpleFile) {
  Base::FileDataProvider fdata("test_input.txt");
  Base::DataProvider& data = fdata;

  // FileDataProvider needs to be set to first line
  data.GoToNextLine();
  BOOST_CHECK_EQUAL(data.GetActualLine(),"18 1000000 0 1\n");
  BOOST_CHECK_EQUAL(data.GetLineBefore(),"");

  // Next step to check if method GetLineBefore works
  data.GoToNextLine();
  BOOST_CHECK_EQUAL(data.GetActualLine(),"18 1000000 0 2\n");
  BOOST_CHECK_EQUAL(data.GetLineBefore(),"18 1000000 0 1\n");

}

BOOST_AUTO_TEST_SUITE_END()
