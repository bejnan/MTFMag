#include "data_collector.h"

namespace Base {

DataCollector::DataCollector(shared_ptr<DataProvider> data_input,
                             shared_ptr<DataOutput> data_output)
    : data_input_(data_input),
      data_output_(data_output) {

}

DataCollector::~DataCollector() {
}

shared_ptr<vector<DataCollector::DataInputLine> > DataCollector::ReadInputLines(
    int turn_amount) {
  string line;
  stringstream input_line_stream;
  vector<DataCollector::DataInputLine> * input_lines_data = new vector<
      DataCollector::DataInputLine>();
  unsigned int interaction, timestamp, sender_id, receiver_id;
  for (int i = 0; i < turn_amount; i++) {
    data_input_->GoToNextLine();
    line = data_input_->GetActualLine();
    input_line_stream.str(line);
    input_line_stream >> interaction >> timestamp >> sender_id >> receiver_id;
    input_lines_data->push_back(
        DataCollector::DataInputLine(interaction, timestamp, sender_id,
                                     receiver_id));
  }
  return shared_ptr<vector<DataCollector::DataInputLine> >(input_lines_data);
}

shared_ptr<DataCollector::DataInputLine> DataCollector::ReadInputLine() {
  string line;
  stringstream input_line_stream;
  unsigned int interaction, timestamp, sender_id, receiver_id;
  data_input_->GoToNextLine();
  line = data_input_->GetActualLine();
  input_line_stream.str(line);
  input_line_stream >> interaction >> timestamp >> sender_id >> receiver_id;
  DataInputLine* new_input_line = new DataInputLine(interaction, timestamp,
                                                   sender_id, receiver_id);
  return shared_ptr<DataInputLine> (new_input_line);
}

void DataCollector::PrintResults(int turn_amount,
                                 shared_ptr<vector<Result> > results) {
  vector<Result>::iterator result_iterator;
  vector<string> results_text;
  for (result_iterator = results->begin(); result_iterator != results->end();
      result_iterator++) {
    results_text.push_back(result_iterator->ToString());
  }
  data_output_->PrintLine(turn_amount, results_text);
}

} /* namespace Base */
