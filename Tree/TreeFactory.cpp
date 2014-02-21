/*
 * TreeFactory.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeFactory.h"
#include <memory>

using std::shared_ptr;

namespace Tree {

TreeFactory::TreeFactory(TreeRoot& root)
    : root_(root) {
}

TreeFactory::~TreeFactory() {
}

template<>
void TreeFactory::AddElement<Element>(int id) {
  Element* elem = new Element(id);
  shared_ptr<Element> elem_ptr(elem);
  int position = root_.tree_list_.size();
  root_.tree_list_.push_back(elem_ptr);
  root_.id_position_[position] = id;
}

void TreeFactory::DeleteElement(int id) {
  //TODO
}

} /* namespace Tree */
