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
 * Interface for creators of Processors for simple users (sources of notifications).
 * Every user that is source of notification should be represent by
 * Processor and ProcessorFactory creates that Processors.
 * It is used in DataCollector when user from input data doesn't
 * have Processor representation.
 * @see Base::DataCollector
 */
class ProcessorFactory {
 public:
  virtual ~ProcessorFactory() {   }
  /**
   * Generates Processor for given user by its identifier
   * @param user_id Identifier of user
   * @return Instance of Processor for given user
   */
  virtual shared_ptr<Processor> GenerateProcessor(int user_id) = 0;
};

} /* namespace Tools */

#endif /* PROCESSORFACTORY_H_ */
