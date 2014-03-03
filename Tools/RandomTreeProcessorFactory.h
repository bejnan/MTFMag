/*
 * RandomTreeProcessorFactory.h
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#ifndef RANDOMTREEPROCESSORFACTORY_H_
#define RANDOMTREEPROCESSORFACTORY_H_

#include "ProcessorFactory.h"
#include "RandomTreeProcessor.h"

namespace Tools {

class RandomTreeProcessorFactory : public ProcessorFactory {
 public:
  RandomTreeProcessorFactory();
  virtual ~RandomTreeProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int id);
 private:
  string algorithm_name_;
};

} /* namespace Tools */

#endif /* RANDOMTREEPROCESSORFACTORY_H_ */
