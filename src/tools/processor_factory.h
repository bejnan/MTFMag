#pragma once

#include "processor.h"
#include "../headers/algorithms.h"
#include "judges.h"

#include <memory>

using std::shared_ptr;

namespace Tools {
/**
 * Creator of Processors for simple users (sources of notifications).
 * Every user that is a source of notification should be represent by
 * Processor. ProcessorFactory creates that Processors for DataCollector.
 * It is used to give every user from input representation as Processor.
 * @see Base::DataCollector
 * @see Tools::Processor
 */

class ProcessorFactory {
 public:
  ProcessorFactory(shared_ptr<Algorithms::Algorithm> algorithm_prototype, shared_ptr<Judge> judge_prototype);
   ~ProcessorFactory();

   /**
   * Generates Processor for given user by its identifier.
   * Child classes defines details about what algorithm and judge to use
   * @param user_id Identifier of user
   * @return Instance of Processor for given user
   */
  shared_ptr<Processor> GenerateProcessor(int user_id);

 private :
  shared_ptr<Algorithms::Algorithm> algorithm_prototype_;
  shared_ptr<Judge> judge_prototype_;
};

} /* namespace Tools */
