/*
 * result_collector.cpp
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#include "result_collector.h"

namespace Base {

ResultCollector::ResultCollector(shared_ptr<DataCollector> data_collector, shared_ptr<JudgeCollector> judge_collector) :
  data_collector_(data_collector),
  judge_collector_(judge_collector),
  learn_turns_(0),
  test_turns_(0),
  turns_between_results_(0),
  was_already_run_(false) {

}

ResultCollector::~ResultCollector() {
}

void ResultCollector::SetTurns(int learn_turns, int test_turns) {
  learn_turns_ = learn_turns;
  test_turns_ = test_turns;
}

void ResultCollector::SetResultFrequency(int turn_count) {
  turns_between_results_ = turn_count;
}

void ResultCollector::Run() {
  if (!was_already_run_)
  {

  }
  else
    return;
}

} /* namespace Base */
