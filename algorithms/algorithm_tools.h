/*
 * algorithm_tools.h
 *
 *  Created on: May 28, 2014
 *      Author: kuba
 */

#ifndef ALGORITHM_TOOLS_H_
#define ALGORITHM_TOOLS_H_

#include "algorithm.h"
#include "matrix.h"
#include "tree.h"
#include "../headers/elements.h"

#include <map>
#include <memory>

using std::map;
using std::shared_ptr;

namespace Algorithms {

/**
 * Static method to get access to all algorithms.
 * Make ResultCollector easier to configurable.
 * There is no need to use only this method.
 * @param element_prototype Prototype of element to use in algorithms.
 * @return Dictionary of algorithms with their names as key.
 */
static map<string, shared_ptr<Algorithm> > GetAllAlgorithms(
    shared_ptr<Base::Element> element_prototype =
        Base::SimpleElement::GetPrototype()) {
  static map<string, shared_ptr<Algorithm> > algorithms;
  algorithms[MTFMatrix::AlgorithmName()] = shared_ptr<Algorithm>(
      new MTFMatrix(element_prototype));
  algorithms[MoveToFront::AlgorithmName()] = shared_ptr<Algorithm>(
      new MoveToFront(element_prototype));
  algorithms[TreeRoot::AlgorithmName()] = shared_ptr<Algorithm>(
      new TreeRoot(element_prototype));
  algorithms[RandomTreeRoot::AlgorithmName()] = shared_ptr<Algorithm>(
      new RandomTreeRoot(element_prototype));

  return algorithms;
}

/**
 * Easy Algorithm instance generator
 * @return
 */
template <class Method, class Element>
shared_ptr<Algorithm> GetSpecificAlgorithm() {
  Method* method = new Method(Element::GetPrototype());
  return shared_ptr<Algorithm>(method);
}

} /* namespace Algorithms */

#endif /* ALGORITHM_TOOLS_H_ */
