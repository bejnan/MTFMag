#include "algorithm_container.h"

namespace Algorithms {

AlgorithmContainer::AlgorithmContainer() {
    Algorithm* tree = new TreeRoot(Base::SimpleElement::GetPrototype());
    AddAlgorithm(shared_ptr<Algorithm>(tree));
    Algorithm* random_tree = new RandomTreeRoot(Base::SimpleElement::GetPrototype());
    AddAlgorithm(shared_ptr<Algorithm>(random_tree));
    Algorithm* move_to_front = new MoveToFront(Base::SimpleElement::GetPrototype());
    AddAlgorithm(shared_ptr<Algorithm>(move_to_front));
    Algorithm* matrix = new MTFMatrix(Base::SimpleElement::GetPrototype());
    AddAlgorithm(shared_ptr<Algorithm>(matrix));
}

AlgorithmContainer& AlgorithmContainer::GetInstance() {
  static AlgorithmContainer instance;
  return instance;
}

void AlgorithmContainer::AddAlgorithm(shared_ptr<Algorithm> algorithm) {
  if (_algorithms_set.find(algorithm->GetAlgorithmName())
      == _algorithms_set.end()) {
    _algorithms_set[algorithm->GetAlgorithmName()] = algorithm;
  }
}


shared_ptr<Algorithm> AlgorithmContainer::GetAlgorithm(string algorithm_name) {
  return _algorithms_set.at(algorithm_name);
}

}
