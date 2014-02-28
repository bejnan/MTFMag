/*
 * ProcessorFactory.cpp
 *
 *  Created on: Feb 28, 2014
 *      Author: kuba
 */

#include "ProcessorFactory.h"
#include "TreeProccessor.h"

namespace Tools {

ProcessorFactory::ProcessorFactory() {
}

ProcessorFactory::~ProcessorFactory() {
}

template<>
shared_ptr<Processor> ProcessorFactory::GenerateProcessor<TreeProcessor>(int id)
{
  Processor* new_proc = new TreeProcessor(id,"TreeAlgorithm");
  return shared_ptr<Processor>(new_proc);
}

} /* namespace Tools */
