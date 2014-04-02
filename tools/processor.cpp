/*
 * Processor.cpp
 *
 *  Created on: Feb 26, 2014
 *      Author: Jakub Banaszewski
 */

#include "processor.h"
namespace Tools {

Processor::Processor(int user_id, string identifier)
    : user_id_(user_id),
      identifier_(identifier) {
}

Processor::~Processor() {
}

}

