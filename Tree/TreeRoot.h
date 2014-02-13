/*
 * TreeRoot.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEROOT_H_
#define TREEROOT_H_

#include "../Headers/Elements.h"
#include "Classes.h"
#include <vector>
#include <map>

using Base::Element;
using std::vector;
using std::map;

namespace Tree {

class TreeRoot {
  friend class TreeFactory;
 public:
  TreeRoot();
  virtual ~TreeRoot();
  void NotifyContent(int id);
  int GetContentPosition(int id);
 private:
  vector<Element> tree_list_;
  vector<Element> sorted_content_list_;
  map<int, int> id_position_;
};

} /* namespace Tree */

#endif /* TREEROOT_H_ */
