/*
 * result.h
 *
 *  Created on: May 30, 2014
 *      Author: kuba
 */

#ifndef RESULT_H_
#define RESULT_H_

#include "../../headers/tools.h"

#include<vector>
#include<memory>

using std::vector;
using std::to_string;
using std::string;
using std::shared_ptr;
using std::pair;

namespace Base {

class Result {
 public:
  Result(int overal_penalty, shared_ptr<vector<int> > penalty_history, int timestamp, string comment = "");
  Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp, string comment = "");
  virtual ~Result();
  virtual string ToString();
  virtual string HeaderLine();
 private:
  int overal_penalty_;
  shared_ptr< vector<pair< int, int> > > penalty_history_;
  int timestamp_;
  string comment_;

};

} /* namespace Base */

#endif /* RESULT_H_ */
