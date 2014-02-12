/*
 * Leaf.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef LEAF_H_
#define LEAF_H_

#include "Node.h"

namespace Tree {

// Implementation of tree leaf. It contains only Element content.
class Leaf : public Tree::Node {
 public:
  Leaf(shared_ptr<Element> elem);
  virtual ~Leaf();
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> son_content);
  using left_son;
  using right_son;
  using content;
  using children_count;
};

} /* namespace Tree */

#endif /* LEAF_H_ */
