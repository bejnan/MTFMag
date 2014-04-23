/*
 * TreeRoot.h
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef TREEROOT_H_
#define TREEROOT_H_

#include "../../headers/elements.h"
#include "../algorithm.h"
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;
using std::shared_ptr;

namespace Tree {

/**
 * This algorithm similar as Move To Front moves chosen element
 * to first position. Difference is in a way it happens.
 * All elements are stored in full binary tree and every notification moves
 * element up to root node replacing other nodes in it's path.
 * For example, lets tree look like : <pre>
 *     1
 *   2   3
 *  4 5 6 7
 * </pre>
 *
 * After notify element with identifier 5 tree will look : <pre>
 *     5
 *   1   3
 *  4 2 6 7
 * </pre>
 *
 */
class TreeRoot : public Base::Algorithm  {

 public:
  TreeRoot(shared_ptr<Base::Element> node_core_prototype);
  virtual ~TreeRoot();

  virtual void NotifyContent(int user_id);

  virtual void NotifyContent(int user_id, int notification_counter);

  virtual int GetContentPosition(int user_id);

  virtual void AddElement(int user_id);

  virtual bool HaveElement(int user_id) = 0;

 protected:
  // Moves element to top of the tree.
  virtual void MoveFromPositionToFront(int position);
  // Swap elements on positions.
  virtual void SwapElementsOnPositions(int position1, int position2);
  // Getter of element on position in tree
  shared_ptr<Base::Element> GetElement(int position);
  // Sort elements in each level by its value.
  // Method used to refresh sorted_content_list.
  void SortElementToList();
  //todo
  int CompareElementsOnPositions(int position1, int position2);
 private:
  // Tree implemented by array (parent is on child's position div 2)
  vector<shared_ptr<Base::Element> > tree_list_;
  // List of elements in order (level priority, then value)
  vector<int> sorted_content_list_;
  // Map to get position of element in tree
  map<int, int> id_position_;
  // Prototype element, which is a core of node
  shared_ptr<Base::Element> node_core_prototype;
};

} /* namespace Tree */

#endif /* TREEROOT_H_ */
