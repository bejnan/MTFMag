/*
 * TreeRoot.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeRoot.h"

namespace Tree {

TreeRoot::TreeRoot() {
}

TreeRoot::~TreeRoot() {
}

void TreeRoot::NotifyContent(int id) {
  int position = id_position_.at(id);
  tree_list_[position]->Notify();
  MoveElement(position);
  SortElements();
}

int TreeRoot::GetContentPosition(int id) {
  for (int i = 0; i < sorted_content_list_.size(); i++) {
    if (sorted_content_list_[i] == id)
      return (i + 1);
  }
  return -1;
}

void TreeRoot::MoveElement(int position) {
  shared_ptr<Base::Element> tmp_elem;
  while (position > 1) {
    tmp_elem = tree_list_[position];
    tree_list_[position] = tree_list_[position / 2];
    tree_list_[position / 2] = tmp_elem;
    position /= 2;
  }
}

void TreeRoot::SortElements() {
//TODO
}

} /* namespace Tree */
