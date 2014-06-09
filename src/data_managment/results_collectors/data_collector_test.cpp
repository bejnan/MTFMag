#include "data_collector.h"
#include "../data_providers.h"
#include "../data_outputs.h"

#include "../../headers/tools.h"
#include "../../headers/exceptions.h"
#include "../../headers/algorithms.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <memory>

using std::shared_ptr;

BOOST_AUTO_TEST_SUITE(DataCollector)

//Test single line reader
BOOST_AUTO_TEST_CASE(DataCollector_ReadInputLine) {
  //initialization
  Base::DataProvider* file_data_provider = new Base::FileDataProvider(
      "test_input.txt");
  shared_ptr<Base::DataProvider> data_provider_ptr(file_data_provider);
  Base::DataOutput* console_data_output = new Base::CsvDataOutput('|');
  shared_ptr<Base::DataOutput> data_output_ptr(console_data_output);
  Base::DataCollector data_collector(data_provider_ptr, data_output_ptr);

  //test
  shared_ptr<Base::DataProvider::DataInputLine> input_line = data_collector
      .ReadInputLine();
  BOOST_CHECK_EQUAL(input_line->interaction_type_, 18);
  BOOST_CHECK_EQUAL(input_line->sender_id_,  10);
  BOOST_CHECK_EQUAL(input_line->receiver_id_, 1);
  BOOST_CHECK_EQUAL(input_line->timestamp_, 1000000);
}

//Test multiple lines reader
BOOST_AUTO_TEST_CASE(DataCollector_ReadInputLines) {
  //initialization
  Base::DataProvider* file_data_provider = new Base::FileDataProvider(
      "test_input.txt");
  shared_ptr<Base::DataProvider> data_provider_ptr(file_data_provider);
  Base::DataOutput* console_data_output = new Base::CsvDataOutput('|');
  shared_ptr<Base::DataOutput> data_output_ptr(console_data_output);
  Base::DataCollector data_collector(data_provider_ptr, data_output_ptr);

  //test
  shared_ptr<vector<Base::DataProvider::DataInputLine> > input_lines =
      data_collector.ReadInputLines(2);

  Base::DataProvider::DataInputLine input_line = (*input_lines)[0];

  BOOST_CHECK_EQUAL(input_line.interaction_type_, 18);
  BOOST_CHECK_EQUAL(input_line.sender_id_, 10);
  BOOST_CHECK_EQUAL(input_line.receiver_id_, 1);
  BOOST_CHECK_EQUAL(input_line.timestamp_, 1000000);

  Base::DataProvider::DataInputLine second_input_line = (*input_lines)[1];

  BOOST_CHECK_EQUAL(second_input_line.interaction_type_, 18);
  BOOST_CHECK_EQUAL(second_input_line.sender_id_, 10);
  BOOST_CHECK_EQUAL(second_input_line.receiver_id_, 2);
  BOOST_CHECK_EQUAL(second_input_line.timestamp_, 1000000);
}

BOOST_AUTO_TEST_SUITE_END()
