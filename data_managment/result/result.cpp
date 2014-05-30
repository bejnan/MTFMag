/*
 * result.cpp
 *
 *  Created on: May 30, 2014
 *      Author: kuba
 */

#include "result.h"

namespace Base {

Result::Result(int overal_penalty, shared_ptr<vector<int> > penalty_history, int timestamp, string comment)
    : overal_penalty_(overal_penalty),
      penalty_history_(penalty_history),
      timestamp_(timestamp),
      comment_(comment) {
}

Result::Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp,
               string comment)
    : overal_penalty_(processor_ptr->GetPenalty()),
      penalty_history_(processor_ptr->GetPenaltyDetails()),
      timestamp_(timestamp),
      comment_(comment) {
}

Result::~Result() {
}
string Result::HeaderLine() {
  return "timestamp    penalty\n";
}

string Result::ToString() {
  string result = to_string(timestamp_) + "    " + to_string(overal_penalty_)
      + "\n";
  return result;
}

} /* namespace Base */
