/*
 * TreeFactory.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEFACTORY_H_
#define TREEFACTORY_H_

#include "Classes.h"

namespace Tree {

class TreeFactory {
 public:
  TreeFactory(TreeRoot& root);
  virtual ~TreeFactory();
  void AddElement(int id);
  void DeleteElement(int id);
 private :
  TreeRoot& root_;
};

} /* namespace Tree */

#endif /* TREEFACTORY_H_ */
