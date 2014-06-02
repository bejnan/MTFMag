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

  Result(string algorithm_name, int source_id, int overal_penalty,
         int timestamp, string comment = "");

  Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp,
         string comment = "");

  virtual ~Result();

  virtual string HeaderLine();

  virtual string ToString();

 protected:
  const string& GetAlgorithmName() const;

  const string& GetComment() const;

  int GetOveralPenalty() const;

  int GetSourceId() const;

  int GetTimestamp() const;

 private:

  string algorithm_name_;

  int source_id_;

  int overal_penalty_;

  int timestamp_;

  string comment_;

};

} /* namespace Base */

#endif /* RESULT_H_ */
