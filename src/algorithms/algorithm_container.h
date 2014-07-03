#ifndef ALGORITHM_TOOLS_H_
#define ALGORITHM_TOOLS_H_

#include "algorithm.h"
#include "matrix_algorithms.h"
#include "tree_algorithms.h"
#include "move_to_front_algorithms.h"

#include "../headers/elements.h"

#include <map>
#include <memory>
#include <vector>

using std::map;
using std::vector;
using std::shared_ptr;

namespace Algorithms {

class AlgorithmContainer {
 public:

  static shared_ptr<AlgorithmContainer> getInstance();

  void AddAlgorithm(shared_ptr<Algorithm> algorithm);

 private:

  AlgorithmContainer();

  map<string, shared_ptr<Algorithm> > _algorithms_set;
  shared_ptr<AlgorithmContainer> instance;

};

} /* namespace Algorithms */

#endif /* ALGORITHM_TOOLS_H_ */
