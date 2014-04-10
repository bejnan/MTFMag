#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "data_provider.h"
#include "database.h"
#include "data_output.h"
#include "../headers/tools.h"

#include <sstream>
#include <algorithm>
#include <memory>
#include <vector>

using std::accumulate;
using std::stringstream;
using std::vector;
using std::shared_ptr;
using std::pair;
using std::make_pair;

namespace Base {
/**
 * Class to connect all parts of algorithms.
 *  *\dot
 * digraph G {
 * DataCollector -> Database;
 * DataCollector -> DataProvider;
 * DataCollector -> DataOutput;
 * DataCollector -> ProcessorFactory;
 *
 * Database -> Processor;
 * ProcessorFactory -> Processor;
 *
 * DataProvider -> FileDataProvider;
 * DataOutput -> CsvDataOutput;
 * DataOuptut -> CsvFileDataOutput;
 *
 * Processor -> Tester;
 *
 * }
 *\enddot
 * It provides data to Processors and print penalties.
 *
 */
class DataCollector {
 public:
  DataCollector(DataProvider& data_input, shared_ptr<DataOutput> data_output);
  virtual ~DataCollector();
  /**
   *
   * @param proc
   */
  virtual void AddProccessorFactory(shared_ptr<Tools::ProcessorFactory> proc);
  // turn_amount describes how many lines of input will be used.
  // learn - count no penalty (learn about user)
  virtual void RunTurns(int turn_amount, bool learn = false);
  // Puts actual results using DataOutput instance
  virtual void PrintActualResults(int turns);

  // Return list of algorithms with their results for defined user
  virtual vector<int> GetResult(int user_id);
  // Return overall result of algorithms
  virtual vector<int> GetResultsSum();
  // Return algorithms names
  virtual vector<string> GetAlgorithmsNames();

 private:
  // Run processor with given id and signal to receiver_id
  void RunProcessor(int id, int receiver_id, bool learn = false);
  void AddProcessorsFromFactories(int id);

  DataProvider& data_input_;
  shared_ptr<DataOutput> data_output_;
  Database processors_base_;
  vector<shared_ptr<Tools::ProcessorFactory> > processor_factories_;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
