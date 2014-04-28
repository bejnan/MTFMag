/*
 * RandomTreeProcessorFactory.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: Jakub Banaszewski
 */

#include "random_tree_processor_factory.h"

namespace Tools {

RandomTreeProcessorFactory::RandomTreeProcessorFactory(
    const double moving_up_propability, const double diff_influence)
    : algorithm_name_(
          "RandomTree:" + to_string(moving_up_propability) + ","
              + to_string(diff_influence)),
      MOVING_UP_PROPABILITY(moving_up_propability),
      DIFF_INFLUENCE(diff_influence) {
}

RandomTreeProcessorFactory::~RandomTreeProcessorFactory() {
}

shared_ptr<Processor> RandomTreeProcessorFactory::GenerateProcessor(
    int user_id) {
  Judge* new_judge = new Tester(20, 20);
  shared_ptr<Judge> judge_ptr(new_judge);
  Algorithms::Algorithm* new_algorithm = new Algorithms::RandomTreeRoot(
      Base::SimpleElement::GetPrototype(), MOVING_UP_PROPABILITY, DIFF_INFLUENCE);
  shared_ptr<Algorithms::Algorithm> algorithm_ptr(new_algorithm);
  Processor* new_processor = new Processor(user_id, judge_ptr, algorithm_ptr);
  return shared_ptr<Processor>(new_processor);
}

} /* namespace Tools */
