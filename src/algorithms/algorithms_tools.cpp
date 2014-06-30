#include "algorithm_tools.h"

namespace Algorithms {

map<string, shared_ptr<Algorithm> > GetAllAlgorithms(
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

}
