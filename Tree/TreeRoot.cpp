/*
 * TreeRoot.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "TreeRoot.h"
#include <algorithm>

using std::sort;

namespace Tree {

TreeRoot::TreeRoot() {
  tree_list_.push_back(shared_ptr<Base::Element>());
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
  for (unsigned int i = 0; i < sorted_content_list_.size(); i++) {
    if (sorted_content_list_[i] == id)
      return (i + 1);
  }
  return -1;
}

void TreeRoot::MoveElement(int position) {
  while (position > 1) {
    SwapElements(position, position / 2);
    position /= 2;
  }
}

void TreeRoot::SwapElements(int position1, int position2) {
  shared_ptr<Base::Element> tmp_elem;
  tmp_elem = tree_list_[position1];
  tree_list_[position1] = tree_list_[position2];
  tree_list_[position2] = tmp_elem;

  id_position_[tree_list_[position1]->user_id()] = position1;
  id_position_[tree_list_[position2]->user_id()] = position2;

}

shared_ptr<Base::Element> TreeRoot::GetElement(int position)
{
  return tree_list_[position];
}

inline bool CompareElementPointers(shared_ptr<Base::Element> elem1,
                                   shared_ptr<Base::Element> elem2) {
  return (elem1->Compare(*elem2) > 0);
}

void TreeRoot::SortElements() {
  vector<shared_ptr<Base::Element> > tmp_list_to_sort;
  vector<shared_ptr<Base::Element> >::iterator tree_iterator, sort_iterator;
  sorted_content_list_.clear();
  unsigned int start = 1;
  unsigned int end = 2;
  while (start < tree_list_.size()) {
    tmp_list_to_sort.clear();
    for (tree_iterator = tree_list_.begin() + start;
        tree_iterator != tree_list_.begin() + end
            && tree_iterator != tree_list_.end(); tree_iterator++) {
      tmp_list_to_sort.push_back(*tree_iterator);
    }
    sort(tmp_list_to_sort.begin(), tmp_list_to_sort.end(),
         CompareElementPointers);
    for (sort_iterator = tmp_list_to_sort.begin();
        sort_iterator != tmp_list_to_sort.end(); sort_iterator++) {
      sorted_content_list_.push_back((*sort_iterator)->user_id());
    }
    start = end;
    end <<= 1;
  }
}

} /* namespace Tree */
