#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "../data_providers.h"
#include "../database.h"
#include "../data_outputs.h"
#include "../results.h"
#include "../../headers/tools.h"
#include "../../headers/algorithms.h"

#include <sstream>
#include <algorithm>
#include <memory>
#include <vector>

using std::accumulate;
using std::stringstream;
using std::stringbuf;
using std::vector;
using std::shared_ptr;
using std::pair;
using std::make_pair;

namespace Base {

/**
 * Class responsible for flow of data.
 * Supports processors (algorithms in JudgeCollector) with data and
 * print results.
 */
class DataCollector {
 public:

  DataCollector(shared_ptr<DataProvider> data_input,
                shared_ptr<DataOutput> data_output);

  ~DataCollector();

  shared_ptr<vector<DataProvider::DataInputLine> > ReadInputLines(int turn_amount);

  shared_ptr<DataProvider::DataInputLine> ReadInputLine();

  void PrintResults(int turn_amount, shared_ptr<vector<Result> > results);

  void PrintResultsFromPointers(
      int turn_amount, shared_ptr<vector<shared_ptr<Result> > > results);

  void SetPrintZeroResult(bool zero_result_flag);

 private:
  shared_ptr<DataProvider> data_input_; /**< Source of data to proceed */
  shared_ptr<DataOutput> data_output_; /**< Pointer to result printer */
  bool print_zero_result;

};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
