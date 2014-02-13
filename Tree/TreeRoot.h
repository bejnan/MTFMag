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

template<class Elem>
class TreeFactory;

class TreeRoot {
  friend class TreeFactory<Base::Element>;
 public:
  TreeRoot();
  virtual ~TreeRoot();
  void NotifyContent(int id);
  int GetContentPosition(int id);
 private:
  vector<shared_ptr<Base::Element> > tree_list_;
  vector<shared_ptr<Base::Element> > sorted_content_list_;
  map<int, int> id_position_;
};

} /* namespace Tree */

#endif /* TREEROOT_H_ */
