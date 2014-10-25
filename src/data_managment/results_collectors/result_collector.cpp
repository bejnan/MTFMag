#include "result_collector.h"
#include <memory>
#include <numeric>

using std::make_shared;
using std::accumulate;

namespace Base {

ResultCollector::ResultCollector(shared_ptr<DataCollector> data_collector,
                                 shared_ptr<JudgeCollector> judge_collector)
    : data_collector_(data_collector),
      judge_collector_(judge_collector),
      learn_turns_(0),
      test_turns_(0),
      turns_between_results_(1),
      turns_counter(0) {
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
  data_collector_->PrintHeader();
  judge_collector_->SetLearnMode(true);
  RunLearnTurns();
  judge_collector_->SetLearnMode(false);
  RunTestTurns();
}

void ResultCollector::handleEvent(Base::Result result)
{
	//TODO
}

void ResultCollector::RunLearnTurns() {
  RunDataSet(data_collector_->ReadInputLines(learn_turns_));
  turns_counter = learn_turns_ + 1;
}

void ResultCollector::RunTestTurns() {
  int turns;
  shared_ptr<DataProvider::DataInputLine> input_line_ptr;
  for (turns = 1; turns <= test_turns_; ++turns) {
    input_line_ptr = data_collector_->ReadInputLine();
    RunData(input_line_ptr);
    //data_collector_->PrintResults(); TODO
    if (turns % turns_between_results_ == 0)
      PrintOverallResults(turns_counter, input_line_ptr->timestamp_);
    ++turns_counter;
  }
}

void ResultCollector::RunDataSet(
    shared_ptr<vector<DataProvider::DataInputLine> > input_lines) {
  vector<DataProvider::DataInputLine>::iterator single_line_iterator;
  for (single_line_iterator = input_lines->begin();
      single_line_iterator != input_lines->end(); single_line_iterator++) {
    judge_collector_->AnalyseNotification(*single_line_iterator);
  }
}

void ResultCollector::RunData(
    shared_ptr<DataProvider::DataInputLine> input_line) {
  judge_collector_->AnalyseNotification(*input_line);
}

void ResultCollector::PrintOverallResults(int turn_amount, int timestamp) {
  vector<shared_ptr<Result> > results = extractResultsFromDatabase(timestamp);

  for (auto iterator : results)
  {
    data_collector_->PrintResult(turn_amount, *iterator);
  }
}

vector<shared_ptr<Result>> ResultCollector::extractResultsFromDatabase(int timestamp)
{
	auto penaltySum = [](int acc, shared_ptr<Tools::Processor> p) {return (p->GetPenalty() + acc);};
	vector<shared_ptr<Result> > results;

	for (auto algorithmName : Database::GetInstance().QueryAlgorithmNames())
	{
		auto processor_list = Database::GetInstance().Query(algorithmName);
		int overall_penalty = 0;
		accumulate(processor_list.begin(),processor_list.end(), overall_penalty, penaltySum);
		results.push_back(CreateOverallResult(algorithmName,overall_penalty,timestamp));
	}
	return results;
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
  return make_shared<Result>(OverallResult(algorithm_name,overall_penalty, timestamp));
}

} /* namespace Base */
