/*
 * DataCollector.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "DataCollector.h"

#include <sstream>

using std::stringstream;

namespace Base {

DataCollector::DataCollector(DataProvider& data_input)
    : data_input_(data_input) {
}

DataCollector::~DataCollector() {
}

void DataCollector::AddProccessor(shared_ptr<Tools::Processor> proc) {
  processors_base.AddToBase(proc);
}

void DataCollector::RunTurns(int turn_amount) {
  string line;
  stringstream input_line;
  unsigned int interaction, timestamp, sender_id, receiver_id;
  for (unsigned int turn_iter = 0; turn_iter < turn_amount; turn_iter++) {
    line = data_input_.GetActualLine();
    input_line.str(line);
    input_line >> interaction >> timestamp >> sender_id >> receiver_id;
    RunProcessor(sender_id, receiver_id);
  }
}

void DataCollector::RunProcessor(int id, int receiver_id) {
  vector<shared_ptr<Tools::Processor> >& processors = processors_base.Query(id);
  vector<shared_ptr<Tools::Processor> >::const_iterator processor_iterator;
  for (processor_iterator = processors.begin();
      processor_iterator != processors.end(); processor_iterator++) {
    (*processor_iterator)->proceed(receiver_id);
  }
}

} /* namespace Tree */
