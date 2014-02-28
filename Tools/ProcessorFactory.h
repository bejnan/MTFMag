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
  ProcessorFactory();
  virtual ~ProcessorFactory();
  template <typename T>
  shared_ptr<Processor> GenerateProcessor(int id);
};

} /* namespace Tools */

#endif /* PROCESSORFACTORY_H_ */
