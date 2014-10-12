#include "data_collector.h"

namespace Base {

DataCollector::DataCollector(shared_ptr<DataProvider> data_input,
                             shared_ptr<DataOutput> data_output)
    : data_input_(data_input),
      data_output_(data_output),
      print_zero_result(false) {

}

DataCollector::~DataCollector() {
}

shared_ptr<vector<DataProvider::DataInputLine> > DataCollector::ReadInputLines(
    int turn_amount) {
  string line;

  vector<DataProvider::DataInputLine> * input_lines_data = new vector<
      DataProvider::DataInputLine>();
  for (int i = 0; i < turn_amount; i++) {
    data_input_->GoToNextLine();
    input_lines_data->push_back(data_input_->GetActualLine());
  }
  return shared_ptr<vector<DataProvider::DataInputLine> >(input_lines_data);
}

shared_ptr<DataProvider::DataInputLine> DataCollector::ReadInputLine() {
  data_input_->GoToNextLine();
  DataProvider::DataInputLine* input_line_data =
      new DataProvider::DataInputLine(data_input_->GetActualLine());
  return shared_ptr<DataProvider::DataInputLine>(input_line_data);
}

void DataCollector::PrintHeader() {
  data_output_->PrintColumnTitles();
}

void DataCollector::PrintResult(int turn_amount, Result result) {
    data_output_->PrintLine(Utils::ToString(turn_amount) + result.ToString());
}

void DataCollector::SetPrintZeroResult(bool zero_result_flag) {
  print_zero_result = zero_result_flag;
}

} /* namespace Base */
