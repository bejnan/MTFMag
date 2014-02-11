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

class LTree : Node {
 public:
  LTree(explicit Leaf leaf, shared_ptr<Element> elem);
  virtual ~LTree();
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> son_content);

  virtual shared_ptr<Node> left_son() { return left_son_; }
  using elem;
  using right_son;
  using content;
 private:
  shared_ptr<Node> left_son_;
};

} /* namespace Tools */

#endif /* LTREE_H_ */
