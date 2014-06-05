#ifndef RESULT_COLLECTOR_H_
#define RESULT_COLLECTOR_H_

#include "data_collector.h"
#include "judge_collector.h"

#include "../database.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

namespace Base {

/**
 * Main controller and connector. Switches data between DataCollector and JudgeCollector.
 * Run program for given amount of turns and prints results of algorithms work.
 */
class ResultCollector {
 public:

  /**
   * Constructor initializes DataCollector and JudgeCollector instances.
   * This instances are in use during all program work.
   * @param data_collector Pointer to DataCollector
   * @param judge_collector
   */
  ResultCollector(shared_ptr<DataCollector> data_collector,
                  shared_ptr<JudgeCollector> judge_collector);
  virtual ~ResultCollector();

  void SetTurns(int learn_turns, int test_turns);

  void SetResultFrequency(int turn_count);

  //void SetResultsDetails();

  virtual void Run();

 private:

  void RunLearnTurns();
  void RunTestTurns();
  void RunDataSet(shared_ptr<vector<DataProvider::DataInputLine> > input_lines);
  void RunData(shared_ptr<DataProvider::DataInputLine>  input_line);
  void PrintOverallResults(int turn_amount, int timestamp);
  int GetOverallAlgorithmPenalty(vector<shared_ptr<Tools::Processor> > algorithms_processors);
  shared_ptr<Result> CreateOverallResult(string algorithm_name, int overall_penalty , int timestamp);

  shared_ptr<DataCollector> data_collector_;
  shared_ptr<JudgeCollector> judge_collector_;

  int learn_turns_;
  int test_turns_;
  int turns_between_results_;
  int turns_counter;

  bool was_already_run_;
};

} /* namespace Base */

#endif /* RESULT_COLLECTOR_H_ */
