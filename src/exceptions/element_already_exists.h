/*
 * ElementAlreadyExists.h
 *
 *  Created on: May 22, 2014
 *      Author: kuba
 */

#ifndef ELEMENTALREADYEXISTS_H_
#define ELEMENTALREADYEXISTS_H_

#include <exception>
#include <string>

#include "../utils/utils.h"

using std::string;
using std::exception;

namespace Exception {

class ElementAlreadyExists : public std::exception {
 public:
  ElementAlreadyExists(int id = 0);

  const char * what() const throw () {
    return message_.c_str();
  }
 private:
  string message_;
};

} /* namespace Exception */

#endif /* ELEMENTALREADYEXISTS_H_ */
