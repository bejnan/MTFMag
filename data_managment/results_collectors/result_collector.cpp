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
  RunDataSet(data_collector_->ReadInputLines(learn_turns_));
  turns_counter = learn_turns_ + 1;
}

void ResultCollector::RunTestTurns() {
  int turns;
  shared_ptr<DataCollector::DataInputLine> input_line_ptr;
  for (turns = 1; turns <= test_turns_; ++turns) {
    input_line_ptr = data_collector_->ReadInputLine();
    RunData(input_line_ptr);
    data_collector_->PrintResults(
        turns_counter, judge_collector_->GetResult(input_line_ptr->sender_id_));
    if (turns % turns_between_results_ == 0)
      PrintOverallResults(turns_counter, input_line_ptr->timestamp_);
    ++turns_counter;
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

void ResultCollector::RunData(
    shared_ptr<DataCollector::DataInputLine> input_line) {
  judge_collector_->AnaliseNotification(*input_line);
}

void ResultCollector::PrintOverallResults(int turn_amount, int timestamp) {
  vector<string> algorithms_name =
      Database::GetInstance().QueryAlgorithmNames();
  vector<shared_ptr<Result> >* new_result_vector =
      new vector<shared_ptr<Result> >();
  shared_ptr<vector<shared_ptr<Result> > > result_vector_ptr(new_result_vector);
  for (vector<string>::reverse_iterator name_iterator = algorithms_name.rbegin();
      name_iterator != algorithms_name.rend(); name_iterator++) {
    result_vector_ptr->push_back(
        CreateOverallResult(
            *name_iterator,
            GetOverallAlgorithmPenalty(
                Database::GetInstance().Query(*name_iterator)),
            timestamp));
  }
  data_collector_->PrintResultsFromPointers(turn_amount, result_vector_ptr);
}

int ResultCollector::GetOverallAlgorithmPenalty(
    vector<shared_ptr<Tools::Processor> > algorithms_processors) {
  int sum = 0;
  for (vector<shared_ptr<Tools::Processor> >::iterator processor_iterator =
      algorithms_processors.begin();
      processor_iterator != algorithms_processors.end(); processor_iterator++) {
    sum += (*processor_iterator)->GetPenalty();
  }
  return sum;
}

shared_ptr<Result> ResultCollector::CreateOverallResult(string algorithm_name,
                                                        int overall_penalty,
                                                        int timestamp) {
  Result* new_overall_result = new OverallResult(algorithm_name,
                                                 overall_penalty, timestamp);
  return shared_ptr<Result>(new_overall_result);
}

} /* namespace Base */
