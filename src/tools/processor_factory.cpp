#include "processor_factory.h"

namespace Tools {

ProcessorFactory::ProcessorFactory(
    shared_ptr<Algorithms::Algorithm> algorithm_prototype,
    shared_ptr<Judge> judge_prototype)
    : algorithm_prototype_(algorithm_prototype),
      judge_prototype_(judge_prototype) {

}

ProcessorFactory::~ProcessorFactory() {
}

shared_ptr<Processor> ProcessorFactory::GenerateProcessor(int user_id) {
  Processor* new_processor_instance = new Processor(
      user_id, (judge_prototype_)->Clone(), (algorithm_prototype_)->Clone());
  return shared_ptr<Processor>(new_processor_instance);
}

}

