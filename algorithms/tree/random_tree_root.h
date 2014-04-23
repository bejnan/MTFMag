/*
 * RandomTreeRoot.h
 *
 *  Created on: 3 mar 2014
 *      Author: Jakub Banaszewski
 */

#ifndef RANDOMTREEROOT_H_
#define RANDOMTREEROOT_H_

#include "tree_root.h"

#include <random>

using std::default_random_engine;
using std::uniform_real_distribution;

namespace Tree {
/**
 * Class very similar to TreeRoot.
 * Only difference is MoveElement method.
 * It uses random factor influenced by different
 * between elements to swap during moving element up.
 *
 * Base algorithm is the same. If there is notification
 * of element, algorithm tries to put it to top.
 * During way up there is competition with elements to swap.
 * If element looses, its parent tries to go up.
 */
class RandomTreeRoot : public TreeRoot {
  friend class TreeFactory;
 public:
  RandomTreeRoot(shared_ptr<Base::Element> node_core_prototype,
                 const double moving_up_propability = 0.75,
                 const double diff_influence = 0.5);
  virtual ~RandomTreeRoot();
  virtual void NotifyContent(int user_id);
  using TreeRoot::NotifyContent;
  using TreeRoot::GetContentPosition;
  using TreeRoot::AddElement;
  using TreeRoot::HaveElement;
 protected:
  virtual void MoveFromPositionToFront(int position);
  using TreeRoot::SwapElementsOnPositions;
  using TreeRoot::SortElementToList;
 private :
  // Random utilities
  default_random_engine generator_;
  uniform_real_distribution<double> distribution_;
  int notification_counter_;
  const double MOVING_UP_PROPABILITY;
  const double DIFF_INFLUENCE;
};

} /* namespace Tree */

#endif /* RANDOMTREEROOT_H_ */
