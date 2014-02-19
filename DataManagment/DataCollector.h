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

using std::shared_ptr;

namespace Base {

class DataCollector {
 public:
  DataCollector(DataProvider& data_input);
  virtual ~DataCollector();
  virtual void AddProccessor(shared_ptr<Tools::Processor> proc);
  virtual void RunTurns(int turn_amount);
  virtual int getResult(int userId);
  virtual int getResultsSum();
 private:
  void RunProcessor(int id, int receiver_id);
  DataProvider& data_input_;
  Database processors_base;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
