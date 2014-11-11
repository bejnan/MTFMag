#include "result_collector.h"
#include <memory>
#include <numeric>

using std::make_shared;
using std::accumulate;

namespace Base {

ResultCollector::ResultCollector(shared_ptr<DataCollector> data_collector,
		shared_ptr<JudgeCollector> judge_collector) :
		data_collector_(data_collector), judge_collector_(judge_collector), learn_turns_(
				0), test_turns_(0), turns_between_results_(1), turns_counter(0) {
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

void ResultCollector::handleEvent(Base::Result result) {
	listOfResults.push_back(result);
}

void ResultCollector::RunLearnTurns() {
	auto input_data = data_collector_->ReadInputLines(learn_turns_);
	RunDataSet(input_data);
	turns_counter = learn_turns_ + 1;
}

void ResultCollector::RunTestTurns() {
	int turns;
	for (turns = 1; turns <= test_turns_; ++turns) {
		DataProvider::DataInputLine input_line =
				data_collector_->ReadInputLine();
		RunData(input_line);
		flushResults(turns);
		if (turns % turns_between_results_ == 0)
			PrintOverallResults(turns_counter, input_line.timestamp_);
		++turns_counter;
	}
}

void ResultCollector::RunDataSet(
		vector<DataProvider::DataInputLine>& input_lines) {
	for (auto single_line : input_lines) {
		judge_collector_->AnalyseNotification(single_line);
	}
}

void ResultCollector::RunData(DataProvider::DataInputLine& input_line) {
	judge_collector_->AnalyseNotification(input_line);
}

void ResultCollector::PrintOverallResults(int turn_amount, int timestamp) {
	vector<Result> results = extractResultsFromDatabase(timestamp);

	for (auto iterator : results) {
		data_collector_->PrintResult(turn_amount, iterator);
	}
}

vector<Result> ResultCollector::extractResultsFromDatabase(int timestamp) {
	auto penaltySum =
			[](int acc, shared_ptr<Tools::Processor> p) {return (p->GetPenalty() + acc);};
	vector<Result> results;

	for (auto algorithmName : Database::GetInstance().QueryAlgorithmNames()) {
		auto processor_list = Database::GetInstance().Query(algorithmName);
		int overall_penalty = 0;
		accumulate(processor_list.begin(), processor_list.end(),overall_penalty, penaltySum);
		results.push_back(std::move(OverallResult(algorithmName, overall_penalty,timestamp)));
	}
	return results;
}

int ResultCollector::GetOverallAlgorithmPenalty(
		vector<shared_ptr<Tools::Processor> > algorithms_processors) {
	int sum = 0;
	for (vector<shared_ptr<Tools::Processor> >::iterator processor_iterator =
			algorithms_processors.begin();
			processor_iterator != algorithms_processors.end();
			processor_iterator++) {
		sum += (*processor_iterator)->GetPenalty();
	}
	return sum;
}

void ResultCollector::flushResults(int turn_amount) {
	for (Result r : listOfResults) {
		data_collector_->PrintResult(turn_amount, r);
	}
	listOfResults.clear();
}

} /* namespace Base */
