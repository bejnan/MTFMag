/*
 * DataCollector.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "data_collector.h"

namespace Base {

DataCollector::DataCollector(DataProvider& data_input, shared_ptr<DataOutput> data_output)
    : data_input_(data_input),
      data_output_(data_output) {
}

DataCollector::~DataCollector() {
}

void DataCollector::AddProccessorFactory(
    shared_ptr<Tools::ProcessorFactory> proc) {
  processor_factories_.push_back(proc);
}

void DataCollector::RunTurns(int turn_amount, bool learn) {
  string line;
  stringstream input_line_stream;
  unsigned int interaction, timestamp, sender_id, receiver_id;
  for (int turn_iter = 0; turn_iter < turn_amount; turn_iter++) {
    data_input_.GoToNextLine();
    line = data_input_.GetActualLine();
    input_line_stream.str(line);
    input_line_stream >> interaction >> timestamp >> sender_id >> receiver_id;
    RunProcessor(sender_id, receiver_id, learn);
  }
}

void DataCollector::PrintActualResults(int turns) {
  if (!data_output_->AreTitlesPrinted())
  {
    data_output_->SetColumnTitles(GetAlgorithmsNames());
    data_output_->PrintColumnTitles();
  }
  data_output_->PrintLine(turns, GetResultsSum());
}

vector<int> DataCollector::GetResult(int user_id) {
  vector<shared_ptr<Tools::Processor> >& processors = processors_base_.Query(
      user_id);
  vector<shared_ptr<Tools::Processor> >::const_iterator processor_iterator;
  vector<int> results;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    results.push_back((*processor_iterator)->GetPenalty());
  }
  return results;
}

int SumPenalties(int acc, shared_ptr<Tools::Processor> processor) {
  return acc + processor->GetPenalty();
}

vector<int> DataCollector::GetResultsSum() {
  vector<string> names = processors_base_.QueryKeys();
  vector<shared_ptr<Tools::Processor> > results;
  vector<int> resultsSum;
  int algorithms_sum = 0;
  for (vector<string>::const_iterator names_iterator = names.begin();
      names_iterator != names.end(); names_iterator++) {
    results = processors_base_.Query(*names_iterator);
    algorithms_sum = accumulate(results.begin(), results.end(), 0,
                                SumPenalties);
    resultsSum.push_back(algorithms_sum);
  }
  return resultsSum;
}

vector<string> DataCollector::GetAlgorithmsNames() {
  return processors_base_.QueryKeys();
}

void DataCollector::RunProcessor(int user_sender_id, int user_receiver_id,
                                 bool learn) {
  if (!processors_base_.Exists(user_sender_id)) {
    AddProcessorsFromFactories(user_sender_id);
  }
  vector<shared_ptr<Tools::Processor> >& processors = processors_base_.Query(
      user_sender_id);
  vector<shared_ptr<Tools::Processor> >::const_iterator processor_iterator;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    (*processor_iterator)->Proceed(user_receiver_id, learn);
  }
}

void DataCollector::AddProcessorsFromFactories(int user_id) {
  vector<shared_ptr<Tools::ProcessorFactory> >::iterator factory_iterator;
  shared_ptr<Tools::Processor> new_processor;
  for (factory_iterator = processor_factories_.begin();
      factory_iterator != processor_factories_.end(); factory_iterator++) {
    new_processor = (*factory_iterator)->GenerateProcessor(user_id);
    processors_base_.AddToBase(new_processor);
  }
}

} /* namespace Tree */
