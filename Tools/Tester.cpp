/*
 * Tester.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Tester.h"

namespace Tree {

Tester::Tester(int first_page_list_size, int second_page_list_size)
    : first_page_list_size_(first_page_list_size),
      second_page_list_size_(second_page_list_size),
      penalty(0) {
}

Tester::~Tester() {
}

} /* namespace Tree */
