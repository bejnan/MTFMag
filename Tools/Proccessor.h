/*
 * Proccessor.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef PROCCESSOR_H_
#define PROCCESSOR_H_

#include "../Headers/Tree.h"
#include "../Headers/Elements.h"
#include "Tester.h"

using namespace Tree;
using std::string;

namespace Tools {

class Processor {
 public:
  Processor(int userId, string identifier = string());
  virtual ~Processor();
  virtual void Proceed(int id);
  virtual int GetPenalty();
  string identifier() { return identifier_; }
  int user_id() {return user_id_;}
 private:
  const int user_id_;
  const string identifier_;
  TreeRoot root_;
  TreeFactory tree_element_generator_;
  Tester penalty_counter_;
};

} /* namespace Tree */

#endif /* PROCCESSOR_H_ */
