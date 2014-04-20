/*
 * MTFProcessorFactory.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: Jakub Banaszewski
 */

#include "mtf_processor_factory.h"

namespace Tools {

MTFProcessorFactory::MTFProcessorFactory() : algorithm_name_("SimpleMTF") {
}

MTFProcessorFactory::~MTFProcessorFactory() {
}

shared_ptr<Processor> MTFProcessorFactory::GenerateProcessor(int user_id) {
  Processor* new_mtf_proc = new MTFProcessor(user_id,algorithm_name_);
  return shared_ptr<Processor>(new_mtf_proc);
}

} /* namespace Tools */
