/*
 * DataCollector.h
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "data_provider.h"
#include "database.h"
#include "../headers/tools.h"

#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;
using std::pair;
namespace Base {
/*
 * Class to connect all elements.
 * It provides data to Processors and check penalties
 */
class DataCollector {
 public:
  DataCollector(DataProvider& data_input);
  virtual ~DataCollector();
  // Add processor factory to list
  virtual void AddProccessorFactory(shared_ptr<Tools::ProcessorFactory> proc);
  // turn_amount describes how many lines of input will be used.
  // learn - count no penalty (learn about user)
  virtual void RunTurns(int turn_amount, bool learn = false);
  // Return list of algorithms with their results for defined user
  virtual vector<int> GetResult(int userId);
  // Return overall result of algorithms
  virtual vector<int> GetResultsSum();
  // Return algorithms names
  virtual vector<string> GetAlgorithmsNames();

 private:
  // Run processor with given id and signal to receiver_id
  void RunProcessor(int id, int receiver_id, bool learn = false);
  void AddProcessorsFromFactories(int id);
  DataProvider& data_input_;
  Database processors_base_;
  vector< shared_ptr<Tools::ProcessorFactory> > processor_factories_;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
