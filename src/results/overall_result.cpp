/*
 * overall_result.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: kuba
 */

#include "../results/overall_result.h"

namespace Base {

OverallResult::OverallResult(string algorithm_name, int overal_penalty,
                             int timestamp, string comment)
    : Result(algorithm_name, 0, overal_penalty, timestamp, comment) {
}

OverallResult::~OverallResult() {
}

string OverallResult::HeaderLine() {
  return "algorithm_name     timestamp    penalty";
}

string OverallResult::ToString() {
  return algorithm_name_ + "    " + Utils::ToString(timestamp_) + "   "
      + Utils::ToString(overall_penalty_);
}

} /* namespace Base */
