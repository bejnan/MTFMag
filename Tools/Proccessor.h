/*
 * Proccessor.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef PROCCESSOR_H_
#define PROCCESSOR_H_

#include "../Headers/Tree.h"
#include "../Headers/Elements.h"
#include "Tester.h"

using namespace Tree;

namespace Tools {

class Proccessor {
 public:
  Proccessor();
  virtual ~Proccessor();
  virtual void proceed(int id);
 private:
  TreeRoot root_;
  TreeFactory tree_element_generator_;
  Tester penalty_counter_;
};

} /* namespace Tree */

#endif /* PROCCESSOR_H_ */
