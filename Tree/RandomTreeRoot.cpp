/*
 * RandomTreeRoot.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#include "RandomTreeRoot.h"

namespace Tree {

RandomTreeRoot::RandomTreeRoot(shared_ptr<Base::Element> node_core_prototype)
    : TreeRoot(node_core_prototype),
      generator_(default_random_engine()),
      distribution_(uniform_real_distribution<double>(0, 1)) {
}

RandomTreeRoot::~RandomTreeRoot() {
}

void RandomTreeRoot::MoveElement(int position) {
  shared_ptr<Base::Element> tmp_elem;
  while (position > 1) {
    double diff = GetElement(position)->Difference(*GetElement(position / 2));
    if (diff + distribution_(generator_) > 0.5) {
      SwapElements(position, position / 2);
    }
    position /= 2;
  }
}

} /* namespace Tree */
