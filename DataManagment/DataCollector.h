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

class DataCollector {
 public:
  DataCollector(DataProvider& data_input);
  virtual ~DataCollector();
  virtual void AddProccessor(shared_ptr<Tools::Processor> proc);
  virtual void RunTurns(int turn_amount);
  virtual vector<pair<string,int> > getResult(int userId);
  virtual vector<pair<string,int> > getResultsSum();
 private:
  void RunProcessor(int id, int receiver_id);
  DataProvider& data_input_;
  Database processors_base_;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
