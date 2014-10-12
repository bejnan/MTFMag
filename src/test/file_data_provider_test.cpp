#include "../headers/data_managment.h"

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(FileDataProvider)

// Test to check if FileDataProvider reads input in correct way
BOOST_AUTO_TEST_CASE(SimpleFile) {
  Base::FileDataProvider fdata("test_input.txt");
  Base::DataProvider& data = fdata;

  // FileDataProvider needs to be set to first line
  data.GoToNextLine();
  Base::DataProvider::DataInputLine actual_line = data.GetActualLine();
  BOOST_CHECK_EQUAL(actual_line.interaction_type_, 18);
  BOOST_CHECK_EQUAL(actual_line.sender_id_, 10);
  BOOST_CHECK_EQUAL(actual_line.receiver_id_, 1);
  BOOST_CHECK_EQUAL(actual_line.timestamp_, 1000000);

  // Next step to check if method GetLineBefore works
  data.GoToNextLine();
  Base::DataProvider::DataInputLine new_actual_line = data.GetActualLine();
  Base::DataProvider::DataInputLine line_before = data.GetLineBefore();
  BOOST_CHECK_EQUAL(new_actual_line.interaction_type_, 18);
  BOOST_CHECK_EQUAL(new_actual_line.sender_id_, 10);
  BOOST_CHECK_EQUAL(new_actual_line.receiver_id_, 2);
  BOOST_CHECK_EQUAL(new_actual_line.timestamp_, 1000000);

  BOOST_CHECK_EQUAL(line_before.interaction_type_, 18);
  BOOST_CHECK_EQUAL(line_before.sender_id_, 10);
  BOOST_CHECK_EQUAL(line_before.receiver_id_, 1);
  BOOST_CHECK_EQUAL(line_before.timestamp_, 1000000);


}

BOOST_AUTO_TEST_SUITE_END()
