/*
 * DataCollector.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "DataProvider.h"
#include "Database.h"
#include "../Headers/Tools.h"

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
  // Add processor to database.
  virtual void AddProccessor(shared_ptr<Tools::Processor> proc);
  // turn_amount describes how many lines of input will be used.
  // learn - count no penalty (learn about user)
  virtual void RunTurns(int turn_amount, bool learn = false);
  // Return list of algorithms with their results for defined user
  virtual vector<pair<string, int> > GetResult(int userId);
  // Return overall result of algorithms
  virtual vector<pair<string, int> > GetResultsSum();
 private:
  // Run processor with given id and signal to receiver_id
  void RunProcessor(int id, int receiver_id, bool learn = false);
  DataProvider& data_input_;
  Database processors_base_;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
