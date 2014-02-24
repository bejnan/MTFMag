/*
 * TreeFactory.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef TREEFACTORY_H_
#define TREEFACTORY_H_

#include "../Headers/Elements.h"
#include "TreeRoot.h"

using Base::Element;
namespace Tree {

/*
 * Class to generate elements of appropriate type.
 */
class TreeFactory {
 public:
  // root - Root of the tree to with elements will be added.
  TreeFactory(TreeRoot& root);
  virtual ~TreeFactory();

  // Template method. Implemented for Element class and all its successors.
  // id - unique identifier
  template<class T>
  void AddElement(int id);
  void DeleteElement(int id);
 private:
  TreeRoot& root_;
};

} /* namespace Tree */

#endif /* TREEFACTORY_H_ */
