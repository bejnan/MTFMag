/*
 * InvalidIndexException.h
 *
 *  Created on: Feb 20, 2014
 *      Author: kuba
 */

#ifndef INVALIDINDEXEXCEPTION_H_
#define INVALIDINDEXEXCEPTION_H_

#include <exception>

using std::exception;

namespace Exception  {

class InvalidIndexException : public exception{
 public:
  InvalidIndexException();
  virtual ~InvalidIndexException();

  const char * what () const throw ()
   {
     return "No element with that index";
   }
};

} /* namespace Exception */

#endif /* INVALIDINDEXEXCEPTION_H_ */
