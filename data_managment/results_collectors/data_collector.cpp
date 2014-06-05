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
  DataProvider::DataInputLine* input_line_data =
      new DataProvider::DataInputLine(data_input_->GetActualLine());
  return shared_ptr<DataProvider::DataInputLine>(input_line_data);
}

void DataCollector::PrintResults(int turn_amount,
                                 shared_ptr<vector<Result> > results) {
  vector<Result>::iterator result_iterator;
  vector<string> results_text;
  int result_counter = 0;
  for (result_iterator = results->begin(); result_iterator != results->end();
      result_iterator++) {
    results_text.push_back(result_iterator->ToString());
    result_counter += result_iterator->GetOverallPenalty();
  }
  if (print_zero_result || (result_counter > 0)) {
    data_output_->PrintLine(turn_amount, results_text);
  }
}

void DataCollector::PrintResults(
    int turn_amount, shared_ptr<vector<shared_ptr<Result> > > results) {
  vector<shared_ptr<Result> >::iterator result_iterator;
  vector<string> results_text;
  for (result_iterator = results->begin(); result_iterator != results->end();
      result_iterator++) {
    results_text.push_back((*result_iterator)->ToString());
  }
  data_output_->PrintLine(turn_amount, results_text);
}

void DataCollector::SetPrintZeroResult(bool zero_result_flag) {
  print_zero_result = zero_result_flag;
}

} /* namespace Base */
