/*
 * RandomTreeRoot.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#include "random_tree_root.h"

namespace Tree {

RandomTreeRoot::RandomTreeRoot(shared_ptr<Base::Element> node_core_prototype,
                               const double moving_up_propability,
                               const double diff_influence)
    : TreeRoot(node_core_prototype),
      generator_(default_random_engine()),
      distribution_(uniform_real_distribution<double>(0, 1)),
      notification_counter_(0),
      MOVING_UP_PROPABILITY(moving_up_propability),
      DIFF_INFLUENCE(diff_influence) {
}

RandomTreeRoot::~RandomTreeRoot() {
}

void RandomTreeRoot::NotifyContent(int user_id) {
  TreeRoot::NotifyContent(user_id, ++notification_counter_);
}

void RandomTreeRoot::MoveElement(int position) {
  shared_ptr<Base::Element> tmp_elem;
  while (position > 1) {
    double diff = GetElement(position)->Difference(*GetElement(position / 2));
    if (diff * DIFF_INFLUENCE + distribution_(generator_)
        > MOVING_UP_PROPABILITY) {
      SwapElements(position, position / 2);
      position /= 2;
    } else {
      break;
    }
  }
}

} /* namespace Tree */
