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

class TreeFactory;

class TreeRoot {
  friend class TreeFactory;
 public:
  TreeRoot();
  virtual ~TreeRoot();
  void NotifyContent(int id);
  int GetContentPosition(int id);
 protected:
  void MoveElement(int position);
  void SortElements();
 private:
  vector<shared_ptr<Base::Element> > tree_list_;
  vector<int> sorted_content_list_;
  map<int, int> id_position_;
};

} /* namespace Tree */

#endif /* TREEROOT_H_ */
