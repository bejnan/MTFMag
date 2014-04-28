/*
 * move_to_front.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: kuba
 */

#include "move_to_front.h"

namespace Algorithms {

MoveToFront::MoveToFront(shared_ptr<Base::Element> element_prototype)
    : element_prototype_(element_prototype) {
}

MoveToFront::~MoveToFront() {
}

void MoveToFront::NotifyContent(int user_id) {
  int position = element_postion_[user_id];
  algorithm_elements_[position]->Notify();
  MoveFromPositionToFront(position);
}

void MoveToFront::NotifyContent(int user_id, int notification_counter) {
  int position = element_postion_[user_id];
  algorithm_elements_[position]->Notify(notification_counter);
  MoveFromPositionToFront(position);
}

int MoveToFront::GetContentPosition(int user_id) {
  return (element_postion_[user_id] + 1);
}

void MoveToFront::AddElement(int user_id) {
  if (!HaveElement(user_id)) {
    int position = algorithm_elements_.size();
    algorithm_elements_.push_back((element_prototype_)->Clone(user_id));
    element_postion_[user_id] = position;
  }
}

bool MoveToFront::HaveElement(int user_id) {
  return (element_postion_.find(user_id) != element_postion_.end());
}

string MoveToFront::AlgorithmName() {
  return ALGORITHM_NAME;
}

void MoveToFront::MoveFromPositionToFront(int position) {
  shared_ptr<Base::Element> tmp_element;
  for (int iterator = position - 1; iterator > 0; iterator--) {
    tmp_element = algorithm_elements_[iterator - 1];
    algorithm_elements_[iterator - 1] = algorithm_elements_[iterator];
    algorithm_elements_[iterator] = tmp_element;
  }
}

void MoveToFront::SwapElementsOnPositions(int position1, int position2) {
  shared_ptr<Base::Element> element_on_position1 =
      algorithm_elements_[position1];
  shared_ptr<Base::Element> element_on_position2 =
      algorithm_elements_[position2];
  algorithm_elements_[position1] = element_on_position2;
  algorithm_elements_[position2] = element_on_position1;
}

/**
 * Empty method. Elements are already sorted.
 */
void MoveToFront::SortElementToList() {
}

int MoveToFront::CompareElementsOnPositions(int position1, int position2) {
  return algorithm_elements_[position1]->Compare(
      *algorithm_elements_[position2]);
}

double MoveToFront::DifferenceBetweenElementsOnPosition(int position1,
                                                        int position2) {
  return algorithm_elements_[position1]->Difference(
      *algorithm_elements_[position2]);
}

const string ALGORITHM_NAME = "MoveToFront";

} /* namespace Base */
