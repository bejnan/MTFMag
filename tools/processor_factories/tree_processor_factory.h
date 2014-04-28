/*
 * TreeProcessorFactory.h
 *
 *  Created on: 28 lut 2014
 *      Author: Jakub Banaszewski
 */

#ifndef TREEPROCESSORFACTORY_H_
#define TREEPROCESSORFACTORY_H_

#include "../processor_factory.h"
#include "../../headers/algorithms.h"
#include "../../headers/elements.h"
#include "../judges.h"

namespace Tools {

/**
 * Class to generate TreeProcessor instances
 */
class TreeProcessorFactory : public Tools::ProcessorFactory {
 public:
  TreeProcessorFactory();
  virtual ~TreeProcessorFactory();
  virtual shared_ptr<Processor> GenerateProcessor(int user_id);
};

} /* namespace Tools */

#endif /* TREEPROCESSORFACTORY_H_ */
