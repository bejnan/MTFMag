/*
 * Proccessor.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Proccessor.h"

namespace Tools {

Proccessor::Proccessor()
    : root_(TreeRoot()),
      tree_element_generator_(root_),
      penalty_counter_(Tester(20, 20)) {
}

Proccessor::~Proccessor() {
}

void Proccessor::proceed(int id) {

}

} /* namespace Tree */
