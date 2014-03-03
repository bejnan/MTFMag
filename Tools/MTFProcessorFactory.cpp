/*
 * MTFProcessorFactory.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: kuba
 */

#include "MTFProcessorFactory.h"

namespace Tools {

MTFProcessorFactory::MTFProcessorFactory() : algorithm_name_("SimpleMTF") {
}

MTFProcessorFactory::~MTFProcessorFactory() {
}

shared_ptr<Processor> MTFProcessorFactory::GenerateProcessor(int id) {
  Processor* new_mtf_proc = new MTFProcessor(id,algorithm_name_);
  return shared_ptr<Processor>(new_mtf_proc);
}

} /* namespace Tools */
