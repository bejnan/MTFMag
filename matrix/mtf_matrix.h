/*
 * MTFMatrix.h
 *
 *  Created on: Mar 13, 2014
 *      Author: kuba
 */

#ifndef MTFMATRIX_H_
#define MTFMATRIX_H_

#include "../headers/elements.h"


#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using std::vector;
using std::map;
using std::shared_ptr;
using std::sort;

namespace Matrix {

/**
 * Class contains nodes in matrix with constant size rows.
 */
class MTFMatrix {

 public:
  MTFMatrix(int row_size);
  virtual ~MTFMatrix();

  // Check if there is node with given user_id
  virtual bool HaveElement(int user_id);
  // Adds new element to matrix
  virtual void AddElement(shared_ptr<Base::Element> element);
  //Notify element with given id.
  // After notification it is moved up to top of the tree.
  void NotifyContent(int user_id);
  // Gives current position of element in hierarchy.
  int GetContentPosition(int user_id);

 protected:
  // moves element from position to first row
  void MoveFromPositionToFront(int position);
  void SwitchElementsOnPositions(int position1, int position2);
  // sorts elements from element_list to sorder_element_list
  void SortElementToList();
  int CompareElementsOnPositions(int position1,int position2);
  unsigned int ElementCount();
 private:
  int row_size_;
  vector<shared_ptr<Base::Element> > element_list_;
  vector<int> sorted_element_list_;
  // map to show position of node with given id
  map<int, int> id_position_;
};


} /* namespace Matrix */

#endif /* MTFMATRIX_H_ */
