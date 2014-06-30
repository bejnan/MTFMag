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
 * @return Dictionary of algorithms with their names as key.d
 */
map<string, shared_ptr<Algorithm> > GetAllAlgorithms(shared_ptr<Base::Element> element_prototype =
    Base::SimpleElement::GetPrototype());

} /* namespace Algorithms */

#endif /* ALGORITHM_TOOLS_H_ */
