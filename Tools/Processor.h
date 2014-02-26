/*
 * AbstractProcessor.h
 *
 *  Created on: Feb 26, 2014
 *      Author: kuba
 */

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <string>

using std::string;

namespace Tools {
/**
 * Class which runs notifications of actions
 * Every user have its own Processor.
 */
class Processor {
 public:
  Processor(int id, string identifier);
  virtual ~Processor();
  // id - Receiver id
  // learn - if true no penalty is added
  virtual void Proceed(int id, bool learn = false) = 0;
  // return penalty counted by tester
  virtual int GetPenalty() = 0;
  string identifier() {
    return identifier_;
  }
  int user_id() {
    return user_id_;
  }
 private:
  const int user_id_;
  const string identifier_;
};

} /* namespace Tools */

#endif /* ABSTRACTPROCESSOR_H_ */
