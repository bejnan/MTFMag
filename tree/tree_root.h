/*
 * TreeRoot.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEROOT_H_
#define TREEROOT_H_

#include "../headers/elements.h"
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;
using std::shared_ptr;

namespace Tree {

/*
 * Class to manage tree of elements.
 */
class TreeRoot {
  // Give access to private field to add elements.
  friend class TreeFactory;
 public:
  TreeRoot(shared_ptr<Base::Element> node_core_prototype);
  virtual ~TreeRoot();
  // Notify element with given id.
  // After notification it is moved up to top of the tree.
  virtual void NotifyContent(int user_id);
  // Notify element with information of number of all notifications
  void NotifyContent(int user_id, int notification_counter);
  // Gives current position of element in hierarchy.
  int GetContentPosition(int user_id);
  // Adds new node with given id
  void AddElement(int user_id);

 protected:
  // Moves element to top of the tree.
  virtual void MoveElement(int position);
  // Swap elements on positions.
  virtual void SwapElements(int position1, int position2);
  // Getter of element on position in tree
  shared_ptr<Base::Element> GetElement(int position);
  // Sort elements in each level by its value.
  // Method used to refresh sorted_content_list.
  void SortElements();
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
