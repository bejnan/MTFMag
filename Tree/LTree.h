/*
 * LTree.h
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#ifndef LTREE_H_
#define LTREE_H_

#include "Node.h"
#include "Leaf.h"

namespace Tree {

//Element of binary tree with only left son present.
//Right son is empty.
class LTree : public Node {
 public:
  // Leaf is old version of tree before adding element (elem).
  LTree(Leaf& leaf, shared_ptr<Element> elem);
  virtual ~LTree();
  // Methods return new instance of this element (FTree) with new
  // content added in his right son (son_content).
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> son_content);

  virtual shared_ptr<Node> left_son() { return left_son_; }
  using Node::right_son;
  using Node::content;
  virtual int children_count() { return (1 + left_son_->children_count()); }

 protected:
   using Node::tree_position;

 private:
  shared_ptr<Node> left_son_;
};

} /* namespace Tools */

#endif /* LTREE_H_ */
