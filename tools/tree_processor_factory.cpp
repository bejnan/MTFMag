/*
 * TreeProcessorFactory.cpp
 *
 *  Created on: 28 lut 2014
 *      Author: Jakub Banaszewski
 */

#include "tree_processor_factory.h"

namespace Tools {

TreeProcessorFactory::TreeProcessorFactory() : algorithm_name_("TreeMTF") {
}

TreeProcessorFactory::~TreeProcessorFactory() {
}

shared_ptr<Processor> TreeProcessorFactory::GenerateProcessor(int id)
{
  Processor* new_tree_proc = new TreeProcessor(id, algorithm_name_);
  return shared_ptr<Processor> (new_tree_proc);
}

} /* namespace Tools */
