/*
 * ProcessorFactory.h
 *
 *  Created on: Feb 28, 2014
 *      Author: kuba
 */

#ifndef PROCESSORFACTORY_H_
#define PROCESSORFACTORY_H_

#include "Processor.h"

#include <memory>

using std::shared_ptr;

namespace Tools {

class ProcessorFactory {
 public:
  virtual ~ProcessorFactory() {   }
  virtual shared_ptr<Processor> GenerateProcessor(int id) = 0;
};

} /* namespace Tools */

#endif /* PROCESSORFACTORY_H_ */
