/*
 * LTree.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef LTREE_H_
#define LTREE_H_

#include "Node.h"

namespace Tree {

class LTree : public Node {
 public:
  LTree(Node n, Element left_elem);
  virtual ~LTree();
  virtual Node addSon(Node n);
 private :
  Node left_son_;
};

} /* namespace Tools */

#endif /* LTREE_H_ */
