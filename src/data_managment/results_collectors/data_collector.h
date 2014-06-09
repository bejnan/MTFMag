#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "../data_providers.h"
#include "../database.h"
#include "../data_outputs.h"
#include "../results.h"
#include "../../headers/tools.h"
#include "../../headers/algorithms.h"

#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

namespace Base {

/**
 * Connects algorithms with data in both ways.
 * It delivers data from input to algorithms and puts results to output.
 * Input and output depends on DataProvider and DataOutput implementations.
 * This class in part of 4 class mechanism responsible for running program :
 * <ul>
 * <li> DataCollector - controls data flow
 * <li> JudgeCollector - tests algorithms
 * <li> ResultCollector - manage all mechanisms
 * <li> Database - collects algorithms and manage them
 * </ul>
 * @see DataProvider
 * @see DataOutput
 */
class DataCollector {
 public:

  /**
   * Initialize input and output source.
   * @param data_input Pointer to DataProvider instance
   * @param data_output Pointer to DataOutput instance
   */
  DataCollector(shared_ptr<DataProvider> data_input,
                shared_ptr<DataOutput> data_output);

  ~DataCollector();

  /**
   * Returns pointer to vector with input lines
   * @param turn_amount Amount of lines to read
   * @return Pointer to vector with DataInputLine's structures
   * representing lines of input
   * @see DataProvider::DataInputLine
   */
  shared_ptr<vector<DataProvider::DataInputLine> > ReadInputLines(
      int turn_amount);

  /**
   * Returns pointer to single line of input
   * @return Pointer to DataInputLine's structure representing line of input
   * @see DataProvider::DataInputLine
   */
  shared_ptr<DataProvider::DataInputLine> ReadInputLine();

  /**
   * Prints results given by JudgeCollector. Results could be
   * overall or includes only one user. Details depends on
   * Result class implementation. Range of results is not
   * imposed, but their have to be most recent.
   * @param turn_amount Number of turns already analysed
   * @param results Pointer to vector of results
   * @see Result
   */
  void PrintResults(int turn_amount, shared_ptr<vector<Result> > results);

  /**
   * Prints results given by JudgeCollector. Results could be
   * overall or includes only one user. Details depends on
   * Result class implementation. Range of results is not
   * imposed, but their have to be most recent.
   * @param turn_amount Number of turns already analysed
   * @param results Pointer to vector with pointers to results to print
   * @see Result
   */
  void PrintResults(int turn_amount,
                    shared_ptr<vector<shared_ptr<Result> > > results);

  /**
   * Setter of flag deciding if result with no penalty will be printed.
   * @param zero_result_flag - New value of flag
   */
  void SetPrintZeroResult(bool zero_result_flag);

 private:
  const shared_ptr<DataProvider> data_input_; /**< Source of data to proceed */
  const shared_ptr<DataOutput> data_output_; /**< Pointer to result printer */
  bool print_zero_result; /**<  Flag deciding if result with no penalty should be printed */

};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
