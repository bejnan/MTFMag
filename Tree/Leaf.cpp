/*
 * Leaf.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: kuba
 */

#include "Leaf.h"
#include "LTree.h"

namespace Tree {

Leaf::Leaf(shared_ptr<Element> elem)
    : Node(elem) {
}

Leaf::~Leaf() {
}

shared_ptr<Node> Leaf::AddSon(shared_ptr<Element> son_content) {
  LTree* leaf_replacement = new LTree(*this,son_content);
  shared_ptr<Node> leaf_replacament_ptr = shared_ptr<Node>(leaf_replacement);
  return leaf_replacament_ptr;
}

} /* namespace Tree */
