/*
 * MTFMatrix.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: kuba
 */

#include "mtf_matrix.h"
#include "../headers/exceptions.h"

namespace Matrix {

MTFMatrix::MTFMatrix(int row_size)
    : row_size_(row_size) {
}

MTFMatrix::~MTFMatrix() {
}

bool MTFMatrix::HaveElement(int user_id) {
  return (id_position_.find(user_id) != id_position_.end());
}

void MTFMatrix::AddElement(shared_ptr<Base::Element> element) {
  element_list_.push_back(element);
  sorted_element_list_.push_back(element->user_id());
  id_position_[element->user_id()] = element_list_.size() - 1;
}

void MTFMatrix::NotifyContent(int user_id) {
  int position = id_position_.at(user_id);
  MoveFromPositionToFront(position);
}

int MTFMatrix::GetContentPosition(int user_id) {
  return (id_position_.at(user_id) + 1);
}

void MTFMatrix::MoveFromPositionToFront(int position) {
  int min_position;
  unsigned int actual_position;
  for (int row = position / row_size_ - 1; row >= 0; row--) {
    min_position = -1;
    for (int position_in_row = 0; position_in_row < row_size_;
        position_in_row++) {
      if (min_position < 0) {
        min_position = position_in_row + row * row_size_;
      } else {
        actual_position = position_in_row + row * row_size_;
        if (CompareElementsOnPositions(min_position, actual_position) > 0) {
          min_position = actual_position;
        }
      }
    }
    SwitchElementsOnPositions(position, min_position);
    position = min_position;
  }
  SortElementToList();
}

void MTFMatrix::SwitchElementsOnPositions(int position1, int position2) {
  if (position1 == position2)
    return;

  shared_ptr<Base::Element> tmp_element = element_list_[position1];
  element_list_[position1] = element_list_[position2];
  element_list_[position2] = tmp_element;

  int id = element_list_[position1]->user_id();
  id_position_[id] = position1;
  id = element_list_[position2]->user_id();
  id_position_[id] = position2;
}

inline bool CompareElementPointers(shared_ptr<Base::Element> elem1,
                                   shared_ptr<Base::Element> elem2) {
  return (elem1->Compare(*elem2) > 0);
}

/*
 * In this method every row is sorted independently,
 * Order is decided first by row in which is element, secondly by order between elements
 */
void MTFMatrix::SortElementToList() {
  vector<shared_ptr<Base::Element> > tmp_sort_row;
  vector<shared_ptr<Base::Element> >::iterator tmp_sort_row_iterator;
  shared_ptr<Base::Element> actual_element;

  sorted_element_list_.clear();
  for (unsigned int row = 0; row <= (element_list_.size() - 1) / row_size_;
      row++) {
    for (int position_in_row = 0; position_in_row < row_size_;
        position_in_row++) {
      if (position_in_row + row * row_size_ < element_list_.size()) {
        actual_element = element_list_[position_in_row + row * row_size_];
        tmp_sort_row.push_back(actual_element);
      }
    }

    sort(tmp_sort_row.begin(), tmp_sort_row.end(), CompareElementPointers);

    for (tmp_sort_row_iterator = tmp_sort_row.begin();
        tmp_sort_row_iterator < tmp_sort_row.end(); tmp_sort_row_iterator++) {
      sorted_element_list_.push_back((*tmp_sort_row_iterator)->user_id());
    }
    tmp_sort_row.clear();
  }
}

// Method is using comparison from Element class and derived classed
int MTFMatrix::CompareElementsOnPositions(int position1, int position2) {
  return element_list_[position1]->Compare(*element_list_[position2]);
}

unsigned int MTFMatrix::ElementCount() {
  return element_list_.size();
}

} /* namespace Matrix */
