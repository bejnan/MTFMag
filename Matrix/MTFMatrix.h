/*
 * MTFMatrix.h
 *
 *  Created on: Mar 13, 2014
 *      Author: kuba
 */

#ifndef MTFMATRIX_H_
#define MTFMATRIX_H_

#include "../Headers/Elements.h"


#include <vector>
#include <map>
#include <memory>
#include <algorithm>

using std::vector;
using std::map;
using std::shared_ptr;
using std::sort;

namespace Matrix {


class MTFMatrix {

 public:
  MTFMatrix(int row_size);
  virtual ~MTFMatrix();

  virtual bool HaveElement(int id);
  virtual void AddElement(shared_ptr<Base::Element> element);
  //Notify element with given id.
  // After notification it is moved up to top of the tree.
  void NotifyContent(int id);
  // Gives current position of element in hierarchy.
  int GetContentPosition(int id);

 protected:
  void MoveFromPositionToFront(int position);
  void SwitchElementsOnPositions(int position1, int position2);
  void SortElementToList();
  int CompareElementsOnPositions(int position1,int position2);
  unsigned int ElementCount();
 private:
  int row_size_;
  vector<shared_ptr<Base::Element> > element_list_;
  vector<int> sorted_element_list_;
  map<int, int> id_position_;

};


} /* namespace Matrix */

#endif /* MTFMATRIX_H_ */
