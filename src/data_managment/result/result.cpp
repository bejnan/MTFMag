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

Result::~Result() {
}

string Result::HeaderLine() {
  return "algorithm_name     source_id    timestamp    penalty";
}

string Result::ToString() {
  string result = algorithm_name_ + "    " + Utils::ToString(source_id_) + "      "
      + Utils::ToString(timestamp_) + "    " + Utils::ToString(overall_penalty_);
  return result;
}

} /* namespace Base */
