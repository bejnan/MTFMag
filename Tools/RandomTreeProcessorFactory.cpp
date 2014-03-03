/*
 * RandomTreeProcessorFactory.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#include "RandomTreeProcessorFactory.h"

namespace Tools {

RandomTreeProcessorFactory::RandomTreeProcessorFactory()
    : algorithm_name_("RandomTree") {
}

RandomTreeProcessorFactory::~RandomTreeProcessorFactory() {
}

shared_ptr<Processor> RandomTreeProcessorFactory::GenerateProcessor(int id) {
  Processor* new_tree_proc = new RandomTreeProcessor(id, algorithm_name_);
  return shared_ptr<Processor>(new_tree_proc);
}

} /* namespace Tools */
