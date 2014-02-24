/*
 * TreeRoot.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEROOT_H_
#define TREEROOT_H_

#include "../Headers/Elements.h"
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;
using std::shared_ptr;

namespace Tree {

// Documentation and implementation in files TreeFactory.h and TreeFactory.cpp
class TreeFactory;

/*
 * Class to manage tree of elements.
 */
class TreeRoot {
  // Give access to private field to add elements.
  friend class TreeFactory;
 public:
  TreeRoot();
  virtual ~TreeRoot();
  // Notify element with given id.
  // After notification it is moved up to top of the tree.
  void NotifyContent(int id);
  // Gives current position of element in hierarchy.
  int GetContentPosition(int id);
 protected:
  // Moves element to top of the tree.
  void MoveElement(int position);
  // Sort elements in each level by its value.
  // Method used to refresh sorted_content_list.
  void SortElements();
 private:
  // Tree implemented by array (parent is on position child div 2)
  vector<shared_ptr<Base::Element> > tree_list_;
  vector<int> sorted_content_list_;
  map<int, int> id_position_;
};

} /* namespace Tree */

#endif /* TREEROOT_H_ */
