/*
 * ProcessorFactory.h
 *
 *  Created on: Feb 28, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef PROCESSORFACTORY_H_
#define PROCESSORFACTORY_H_

#include "processor.h"

#include <memory>

using std::shared_ptr;

namespace Tools {
/**
 * Interface to create Processors independently.
 * It provides prepared processors for DataCollectors
 */
class ProcessorFactory {
 public:
  virtual ~ProcessorFactory() {   }
  // Method generating processor for user with specific Id
  virtual shared_ptr<Processor> GenerateProcessor(int id) = 0;
};

} /* namespace Tools */

#endif /* PROCESSORFACTORY_H_ */
