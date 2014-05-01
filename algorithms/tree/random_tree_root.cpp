#include "random_tree_root.h"

namespace Algorithms {

RandomTreeRoot::RandomTreeRoot(shared_ptr<Base::Element> node_core_prototype,
                               const double moving_up_propability,
                               const double diff_influence)
    : TreeRoot(node_core_prototype),
      generator_(default_random_engine()),
      distribution_(uniform_real_distribution<double>(0, 1)),
      notification_counter_(0),
      MOVING_UP_PROBABILITY(moving_up_propability),
      DIFF_INFLUENCE(diff_influence) {
}

RandomTreeRoot::~RandomTreeRoot() {
}

string RandomTreeRoot::AlgorithmName() {
  return RandomTreeRoot::ALGORITHM_NAME + " " + (to_string(MOVING_UP_PROBABILITY)).substr(0,4) + " "
      + (to_string(DIFF_INFLUENCE)).substr(0,4);
}

void RandomTreeRoot::MoveFromPositionToFront(int position) {
  shared_ptr<Base::Element> tmp_elem;
  while (position > 1) {
    double diff = TreeRoot::DifferenceBetweenElementsOnPosition(position,
                                                                position / 2);
    if (diff * DIFF_INFLUENCE + distribution_(generator_)
        > MOVING_UP_PROBABILITY) {
      SwapElementsOnPositions(position, position / 2);
      position /= 2;
    } else {
      break;
    }
  }
}

const string RandomTreeRoot::ALGORITHM_NAME = "RandomTreeMTF";

} /* namespace Tree */
