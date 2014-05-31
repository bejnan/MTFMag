/*
 * result_collector.cpp
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#include "result_collector.h"

namespace Base {

ResultCollector::ResultCollector(shared_ptr<DataCollector> data_collector,
                                 shared_ptr<JudgeCollector> judge_collector)
    : data_collector_(data_collector),
      judge_collector_(judge_collector),
      learn_turns_(0),
      test_turns_(0),
      turns_between_results_(1),
      turns_counter(0),
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
  if (!was_already_run_) {
    was_already_run_ = true;
    judge_collector_->SetLearnMode(true);
    RunLearnTurns();
    judge_collector_->SetLearnMode(false);
    RunTestTurns();
  } else
    return;
}

void ResultCollector::RunLearnTurns() {
  int sets;
  for (sets = 0; sets < learn_turns_ / turns_between_results_; sets++) {
    RunDataSet(data_collector_->ReadInputLines(turns_between_results_));
    turns_counter += turns_between_results_;
  }
  if (turns_counter < learn_turns_) {
    RunDataSet(data_collector_->ReadInputLines(test_turns_ - turns_counter));
    turns_counter = learn_turns_;
  }
}

void ResultCollector::RunTestTurns() {
  int sets;
  for (sets = 0; sets < test_turns_ / turns_between_results_; sets++) {
    RunDataSet(data_collector_->ReadInputLines(turns_between_results_));
    data_collector_->PrintResults(turns_counter,
                                  judge_collector_->GetResult(1));  //TODO!!
    turns_counter += turns_between_results_;
  }
  if (turns_counter < test_turns_ + learn_turns_) {
    RunDataSet(data_collector_->ReadInputLines(test_turns_ + learn_turns_ - turns_counter));
    turns_counter = test_turns_ + learn_turns_;
  }
}

void ResultCollector::RunDataSet(
    shared_ptr<vector<DataCollector::DataInputLine> > input_lines) {
  vector<DataCollector::DataInputLine>::iterator single_line_iterator;
  for (single_line_iterator = input_lines->begin();
      single_line_iterator != input_lines->end(); single_line_iterator++) {
    judge_collector_->AnaliseNotification(*single_line_iterator);
  }
}

} /* namespace Base */
