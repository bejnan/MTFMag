/*
 * result.cpp
 *
 *  Created on: May 30, 2014
 *      Author: kuba
 */

#include "result.h"

namespace Base {

Result::Result(string algorithm_name, int source_id, int overal_penalty,
               int timestamp, string comment)
    : algorithm_name_(algorithm_name),
      source_id_(source_id),
      overal_penalty_(overal_penalty),
      timestamp_(timestamp),
      comment_(comment) {
}

Result::Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp,
               string comment)

    : algorithm_name_(processor_ptr->AlgorithmName()),
      source_id_(processor_ptr->user_id()),
      overal_penalty_(processor_ptr->GetPenalty()),
      timestamp_(timestamp),
      comment_(comment) {
}

Result::~Result() {
}

string Result::HeaderLine() {
  return "algorithm_name     source_id    timestamp    penalty";
}

string Result::ToString() {
  string result = algorithm_name_ + "    " + to_string(source_id_) + "    "
      + to_string(timestamp_) + "    " + to_string(overal_penalty_);
  return result;
}

} /* namespace Base */

const string& Base::Result::GetAlgorithmName() const {
  return algorithm_name_;
}

const string& Base::Result::GetComment() const {
  return comment_;
}

int Base::Result::GetOveralPenalty() const {
  return overal_penalty_;
}

int Base::Result::GetSourceId() const {
  return source_id_;
}

int Base::Result::GetTimestamp() const {
  return timestamp_;
}
