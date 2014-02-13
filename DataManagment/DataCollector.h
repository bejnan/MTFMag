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

namespace Base {
//TODO
class DataCollector {
 public:
  DataCollector(DataProvider& data_input);
  virtual ~DataCollector();
  virtual void AddProccessor(Tools::Proccessor proc);
  virtual void RunTurns(int turn_amount);
 private:
  DataProvider& data_input_;
  Database proccessors_base;
};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
