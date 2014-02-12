/*
 * FTree.cpp
 *
 *  Created on: Feb 12, 2014
 *      Author: kuba
 */

#include "FTree.h"

namespace Tree {

FTree::FTree(LTree& tree, shared_ptr<Element> new_right_son_content)
    : Node(tree.content()),
      left_son_(tree.left_son()),
      left_son_childer_count_(tree.left_son()->children_count()),
      right_son_childer_count_(0) {
  Leaf* new_right_son = new Leaf(new_right_son_content);
  right_son_ = shared_ptr<Node>(new_right_son);
}

FTree::~FTree() {
}

// Adding son to the smaller child tree
shared_ptr<Node> FTree::AddSon(shared_ptr<Element> new_content) {
  if (left_son_childer_count_ <= right_son_childer_count_){
    shared_ptr<Node> tmp_left_son = left_son_->AddSon(new_content);
    // If sons doesn't changed tmp_left_son is empty.
    // It means new_content is added deeper.
    if (tmp_left_son)
      left_son_ = tmp_left_son;
    ++left_son_childer_count_;
  } else {
    shared_ptr<Node> tmp_right_son = right_son_->AddSon(new_content);
    // As above
    if (tmp_right_son)
      right_son_ = tmp_right_son;
    ++right_son_childer_count_;
  }
  return shared_ptr<Node>();
}

} /* namespace Tree */
