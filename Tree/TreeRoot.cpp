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
  shared_ptr<Base::Element> tmp_elem;
  while (position > 1) {
    tmp_elem = tree_list_[position];
    tree_list_[position] = tree_list_[position / 2];
    tree_list_[position / 2] = tmp_elem;

    id_position_[tree_list_[position]->id()] = position;
    id_position_[tree_list_[position/2]->id()] = position/2;
    position /= 2;
  }
}

inline bool CompareElementPointers(shared_ptr<Base::Element> elem1,
                                   shared_ptr<Base::Element> elem2) {
  return (elem1->Compare(*elem2) < 0);
}

void TreeRoot::SortElements() {
  vector<shared_ptr<Base::Element> > tmp_list_to_sort;
  vector<shared_ptr<Base::Element> >::iterator tree_iterator, sort_iterator;
  sorted_content_list_.clear();
  unsigned int start = 0;
  unsigned int end = 1;
  unsigned int range = 1;
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
      sorted_content_list_.push_back((*sort_iterator)->id());
    }
    start = end;
    range <<= 1;
    end = end + range;
  }
}

} /* namespace Tree */
