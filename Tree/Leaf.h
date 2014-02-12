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
// As left or right son returns empty pointer.
class Leaf : public Node {
 public:
  Leaf(shared_ptr<Element> elem, int tree_position);
  virtual ~Leaf();
  //Return new node in place of this one. New node would be LTree instance.
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> son_content);
  //Other methods are without any change
  using Node::left_son;
  using Node::right_son;
  using Node::content;
  using Node::children_count;

 protected:
  using Node::tree_position;
};

} /* namespace Tree */

#endif /* LEAF_H_ */
