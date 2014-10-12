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

/**
 * Class to point algorithm prototype using it's name
 */

class AlgorithmContainer {
 public:

  static AlgorithmContainer& GetInstance();

  shared_ptr<Algorithm> GetAlgorithm(string algorithm_name);

 private:

  AlgorithmContainer();

  void AddAlgorithm(shared_ptr<Algorithm> algorithm);

  map<string, shared_ptr<Algorithm> > _algorithms_set;

};

} /* namespace Algorithms */

#endif /* ALGORITHM_TOOLS_H_ */
