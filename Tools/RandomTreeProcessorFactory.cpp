/*
 * RandomTreeProcessorFactory.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#include "RandomTreeProcessorFactory.h"

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
  Processor* new_tree_proc = new RandomTreeProcessor(user_id, algorithm_name_,
                                                     MOVING_UP_PROPABILITY,
                                                     DIFF_INFLUENCE);
  return shared_ptr<Processor>(new_tree_proc);
}

} /* namespace Tools */
