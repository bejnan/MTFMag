/*
 * Processor.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: kuba
 */

#include "Processor.h"
namespace Tools {

Processor::Processor(int id, string identifier)
    : user_id_(id),
      identifier_(identifier) {
}

Processor::~Processor() {
}

}

