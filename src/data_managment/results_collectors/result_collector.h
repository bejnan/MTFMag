#pragma once

#include "data_collector.h"
#include "judge_collector.h"

#include "../database.h"
#include "../../headers/utils.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

namespace Base {

/**
 * Main controller and connector. Switches data between DataCollector and JudgeCollector.
 * Run program for given amount of turns and prints results of algorithms work.
 */
class ResultCollector : Utils::EventListener{
 public:

  /**
   * Constructor initializes DataCollector and JudgeCollector instances.
   * This instances are in use during all program work.
   * @param data_collector Pointer to DataCollector that provides data for
   * JudgeCollector
   * @param judge_collector Pointer to JudgeCollector that analyse data and
   * produce results for DataCollector
   */
  ResultCollector(shared_ptr<DataCollector> data_collector,
                  shared_ptr<JudgeCollector> judge_collector);

  /**
   * Empty destructor, nothing to handle
   */
  virtual ~ResultCollector();

  /**
   * Setter of number of turns (input lines) to analyse.
   * @param learn_turns - Number of turns to analyse without counting penalty.
   * @param test_turns - Number of turns to analyse with normal penalty
   * counting and results for output.
   */
  void SetTurns(int learn_turns, int test_turns);

  /**
   * Setter of number of turns (test turn) that define frequency of printing
   *  overall algorithms result
   * @param turn_count How many turns have to pass to print overall results
   *  for algorithms
   */
  void SetResultFrequency(int turn_count);

  //void SetResultsDetails();

  /**
   * Runs data flow between DataCollector and JudgeCollector for given amount of turns (input lines)
   * By calling this method program starts to work. Important note. Before calling this method all
   * parameters have to be set on proper values.
   */
  virtual void Run();

  virtual void handleEvent(Base::Result result);

 private:

  /**
   * Runs given amount of learn turns (line of input) without counting penalty and printing results.
   */
  void RunLearnTurns();

  /**
   * Runs given amount of test turns with penalty counting and printing results.
   */
  void RunTestTurns();

  /**
   * Runs part of input stored in vector (every element is single line of input)
   * @param input_lines pointer to vector with input data
   */
  void RunDataSet(vector<DataProvider::DataInputLine>& input_lines);

  /**
   * Runs single turn with given input line
   * @param input_line pointer to line of input
   */
  void RunData(DataProvider::DataInputLine& input_line);

  /**
   * Collects overall results for all users in one algorithms and prints accumulated results for every algorithm.
   * @param turn_amount Counter of turns that was analysed
   * @param timestamp Timestamp from last input line
   */
  void PrintOverallResults(int turn_amount, int timestamp);

  /**
   * Method to sum results of single algorithm for every user.
   * @param algorithms_processors Processor handling algorithm
   * @return Sum of algorithm penalties
   */
  int GetOverallAlgorithmPenalty(vector<shared_ptr<Tools::Processor> > algorithms_processors);

  vector<Result> extractResultsFromDatabase(int timestamp);

  void flushResults(int turn_amount)
  {
	  for (Result r : listOfResults)
	  {
		  data_collector_->PrintResult(turn_amount,r);
	  }
	  listOfResults.clear();
  }

  /** Pointer to source of data */
  const shared_ptr<DataCollector> data_collector_;
  /** Pointer to main mechanism analysing algorithms*/
  const shared_ptr<JudgeCollector> judge_collector_;

  vector<Result> listOfResults;

  /** Number of turns Run method will count no penalty */
  int learn_turns_;
  /** Number of turns Run method will proceed */
  int test_turns_;
  /** Number of turn distance between printing overall algorithms results */
  int turns_between_results_;
  /** Counter of turns that was analysed */
  int turns_counter;

};

} /* namespace Base */
