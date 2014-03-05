/*
 * RandomTreeRoot.h
 *
 *  Created on: 3 mar 2014
 *      Author: kuba
 */

#ifndef RANDOMTREEROOT_H_
#define RANDOMTREEROOT_H_

#include "TreeRoot.h"

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
  RandomTreeRoot();
  virtual ~RandomTreeRoot();
  using TreeRoot::GetContentPosition;
  using TreeRoot::NotifyContent;
 protected:
  virtual void MoveElement(int position);
  using TreeRoot::SwapElements;
  using TreeRoot::SortElements;
 private :
  // Random utilities
  default_random_engine generator_;
  uniform_real_distribution<double> distribution_;
};

} /* namespace Tree */

#endif /* RANDOMTREEROOT_H_ */
