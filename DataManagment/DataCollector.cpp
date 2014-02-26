/*
 * DataCollector.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "DataCollector.h"

#include <sstream>
#include <algorithm>

using std::accumulate;
using std::stringstream;
using std::make_pair;

namespace Base {

DataCollector::DataCollector(DataProvider& data_input)
    : data_input_(data_input) {
}

DataCollector::~DataCollector() {
}

void DataCollector::AddProccessor(shared_ptr<Tools::TreeProcessor> proc) {
  processors_base_.AddToBase(proc);
}

void DataCollector::RunTurns(int turn_amount, bool learn) {
  string line;
  stringstream input_line;
  unsigned int interaction, timestamp, sender_id, receiver_id;
  for (int turn_iter = 0; turn_iter < turn_amount; turn_iter++) {
    data_input_.GoToNextLine();
    line = data_input_.GetActualLine();
    input_line.str(line);
    input_line >> interaction >> timestamp >> sender_id >> receiver_id;
    RunProcessor(sender_id, receiver_id, learn);
  }
}

void DataCollector::RunProcessor(int id, int receiver_id, bool learn) {
  vector<shared_ptr<Tools::TreeProcessor> >& processors = processors_base_.Query(
      id);
  vector<shared_ptr<Tools::TreeProcessor> >::const_iterator processor_iterator;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    (*processor_iterator)->Proceed(receiver_id, learn);
  }
}

vector<pair<string, int> > DataCollector::GetResult(int userId) {
  vector<shared_ptr<Tools::TreeProcessor> >& processors = processors_base_.Query(
      userId);
  vector<shared_ptr<Tools::TreeProcessor> >::const_iterator processor_iterator;
  vector<pair<string, int> > results;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    results.push_back(
        make_pair((*processor_iterator)->identifier(),
                  (*processor_iterator)->GetPenalty()));
  }
  return results;
}

int SumPenalties(int acc, shared_ptr<Tools::TreeProcessor> processor) {
  return acc + processor->GetPenalty();
}

vector<pair<string, int> > DataCollector::GetResultsSum() {
  vector<string> names = processors_base_.QueryKeys();
  vector<shared_ptr<Tools::TreeProcessor> > results;
  vector<pair<string, int> > resultsSum;
  int algorithms_sum = 0;
  for (vector<string>::const_iterator names_iterator = names.begin();
      names_iterator != names.end(); names_iterator++) {
    results = processors_base_.Query(*names_iterator);
    algorithms_sum = accumulate(results.begin(), results.end(), 0,
                                SumPenalties);
    resultsSum.push_back(make_pair(*names_iterator, algorithms_sum));
  }
  return resultsSum;
}

} /* namespace Tree */
