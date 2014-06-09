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
#include <vector>

using std::map;
using std::vector;
using std::shared_ptr;

namespace Algorithms {

/**
 * Easy way to get algorithm instance by it's name.
 * IMPORTANT!! Returned instances of algorithm should be used only as Prototype!
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
 * Static method to get all available algorithms names.
 * Helps with creating program from configuration.
 * @return Vector of all implemented algorithms names
 */
static vector<string> AvailableAlgorithms() {
  static vector<string> algorithms;
  algorithms.push_back(MTFMatrix::AlgorithmName());
  algorithms.push_back(MoveToFront::AlgorithmName());
  algorithms.push_back(TreeRoot::AlgorithmName());
  algorithms.push_back(RandomTreeRoot::AlgorithmName());
  return algorithms;
}


/**
 * Easy template to generate algorithm instance
 * @return Algorithm with default parameters
 */
template <class Method, class Element>
shared_ptr<Algorithm> GetSpecificAlgorithm() {
  Method* method = new Method(Element::GetPrototype());
  return shared_ptr<Algorithm>(method);
}

} /* namespace Algorithms */

#endif /* ALGORITHM_TOOLS_H_ */
