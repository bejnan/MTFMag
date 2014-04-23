/*
 * TreeRoot.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "tree_root.h"
#include <algorithm>

using std::sort;

namespace Tree {

TreeRoot::TreeRoot(shared_ptr<Base::Element> node_core_prototype)
    : node_core_prototype(node_core_prototype) {
  tree_list_.push_back(shared_ptr<Base::Element>());
}

TreeRoot::~TreeRoot() {
}

void TreeRoot::NotifyContent(int user_id) {
  int position = id_position_.at(user_id);
  tree_list_[position]->Notify();
  MoveElement(position);
  SortElementToList();
}

void TreeRoot::NotifyContent(int user_id, int notification_counter) {
  int position = id_position_.at(user_id);
  tree_list_[position]->Notify(notification_counter);
  MoveElement(position);
  SortElementToList();
}

int TreeRoot::GetContentPosition(int user_id) {
  for (unsigned int i = 0; i < sorted_content_list_.size(); i++) {
    if (sorted_content_list_[i] == user_id)
      return (i + 1);
  }
  return -1;
}

void TreeRoot::AddElement(int user_id) {
  shared_ptr<Base::Element> new_node = node_core_prototype->Clone(user_id);
  tree_list_.push_back(new_node);
  sorted_content_list_.push_back(user_id);
  id_position_[user_id] = tree_list_.size() - 1;
}

void TreeRoot::MoveElement(int position) {
  while (position > 1) {
    SwitchElementsOnPositions(position, position / 2);
    position /= 2;
  }
}

void TreeRoot::SwitchElementsOnPositions(int position1, int position2) {
  shared_ptr<Base::Element> tmp_elem;
  tmp_elem = tree_list_[position1];
  tree_list_[position1] = tree_list_[position2];
  tree_list_[position2] = tmp_elem;

  id_position_[tree_list_[position1]->user_id()] = position1;
  id_position_[tree_list_[position2]->user_id()] = position2;

}

shared_ptr<Base::Element> TreeRoot::GetElement(int position) {
  return tree_list_[position];
}

inline bool CompareElementPointers(shared_ptr<Base::Element> elem1,
                                   shared_ptr<Base::Element> elem2) {
  return (elem1->Compare(*elem2) > 0);
}

void TreeRoot::SortElementToList() {
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
