#include "result.h"

namespace Base {

Result::Result(string algorithm_name, int source_id, int overal_penalty,
               int timestamp, string comment)
    : algorithm_name_(algorithm_name),
      source_id_(source_id),
      overall_penalty_(overal_penalty),
      timestamp_(timestamp),
      comment_(comment) {
}

Result::Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp,
               string comment)

    : algorithm_name_(processor_ptr->AlgorithmName()),
      source_id_(processor_ptr->user_id()),
      overall_penalty_(processor_ptr->GetPenalty()),
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
      + to_string(timestamp_) + "    " + to_string(overall_penalty_);
  return result;
}

} /* namespace Base */

const string& Base::Result::GetAlgorithmName() const {
  return algorithm_name_;
}

const string& Base::Result::GetComment() const {
  return comment_;
}

const int Base::Result::GetOverallPenalty() const {
  return overall_penalty_;
}

const int Base::Result::GetSourceId() const {
  return source_id_;
}

const int Base::Result::GetTimestamp() const {
  return timestamp_;
}
