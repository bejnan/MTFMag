#include "algorithm_tools.h"

namespace Algorithms {

AlgorithmContainer::AlgorithmContainer() {
  if (instance.use_count() == 0) {
    AlgorithmContainer* container = new AlgorithmContainer();
    instance = shared_ptr<AlgorithmContainer>(container);
  }
}

shared_ptr<AlgorithmContainer> AlgorithmContainer::getInstance() {
  return instance;
}

void AlgorithmContainer::AddAlgorithm(shared_ptr<Algorithm> algorithm) {
  if (_algorithms_set.find(algorithm->GetAlgorithmName())
      == _algorithms_set.end()) {
    _algorithms_set[algorithm->GetAlgorithmName()] = algorithm;
  }
}

}
