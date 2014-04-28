/*
 * MTFProcessorFactory.h
 *
 *  Created on: Mar 3, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef MTFPROCESSORFACTORY_H_
#define MTFPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../judges.h"

namespace Tools {
/**
 * Factory for MTFProcessor class that uses classic Move To Front algorithm.
 */
class MTFProcessorFactory : public Tools::ProcessorFactory {
 public:
  MTFProcessorFactory();
  virtual ~MTFProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);
};

} /* namespace Tools */

#endif /* MTFPROCESSORFACTORY_H_ */
