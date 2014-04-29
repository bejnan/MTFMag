#include "tree_processor_factory.h"

namespace Tools {

TreeProcessorFactory::TreeProcessorFactory() {
}

TreeProcessorFactory::~TreeProcessorFactory() {
}

shared_ptr<Processor> TreeProcessorFactory::GenerateProcessor(int user_id) {
  Judge* new_judge = new Tester(20, 20);
  shared_ptr<Judge> judge_ptr(new_judge);
  Algorithms::Algorithm* new_algorithm = new Algorithms::TreeRoot(
      Base::SimpleElement::GetPrototype());
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);
  Processor* new_processor = new Processor(user_id, judge_ptr, algorithm_ptr);
  return shared_ptr<Processor>(new_processor);
}

} /* namespace Tools */
