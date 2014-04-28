/*
 * MTFProcessorFactory.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: Jakub Banaszewski
 */

#include "mtf_processor_factory.h"

namespace Tools {

MTFProcessorFactory::MTFProcessorFactory() {
}

MTFProcessorFactory::~MTFProcessorFactory() {
}

shared_ptr<Processor> MTFProcessorFactory::GenerateProcessor(int user_id) {
  Judge* new_judge = new Tester(20, 20);
  shared_ptr<Judge> judge_ptr(new_judge);
  Algorithms::Algorithm* new_algorithm = new Algorithms::MoveToFront(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);
  Processor* new_processor = new Processor(user_id, judge_ptr, algorithm_ptr);
  return shared_ptr<Processor>(new_processor);
  Processor* new_mtf_proc = new Processor(user_id, judge_ptr, algorithm_ptr);
  return shared_ptr<Processor>(new_mtf_proc);
}

} /* namespace Tools */
