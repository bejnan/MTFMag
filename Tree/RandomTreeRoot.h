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
  default_random_engine generator_;
  uniform_real_distribution<double> distribution_;


};

} /* namespace Tree */

#endif /* RANDOMTREEROOT_H_ */
