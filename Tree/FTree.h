/*
 * FTree.h
 *
 *  Created on: Feb 12, 2014
 *      Author: kuba
 */

#ifndef FTREE_H_
#define FTREE_H_

#include "Node.h"

namespace Tree {

class FTree : public Node {
 public:
  FTree(LTree tree, shared_ptr<Element> new_right_son_content);
  virtual ~FTree();
  virtual shared_ptr<Node> AddSon(shared_ptr<Element> new_content);
  virtual shared_ptr<Node> left_son() {return left_son_;}
  virtual shared_ptr<Node> right_son() {return right_son_;}
  using content;
  virtual int children_count() {
    return (2 + left_son_childer_count_ + right_son_childer_count_);
  }
 private :
  shared_ptr<Node> left_son_;
  int left_son_childer_count_;
  shared_ptr<Node> right_son_;
  int right_son_childer_count_;
};

} /* namespace Tree */

#endif /* FTREE_H_ */
