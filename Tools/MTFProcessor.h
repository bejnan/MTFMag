/*
 * MTFProcessor.h
 *
 *  Created on: Mar 2, 2014
 *      Author: kuba
 */

#ifndef MTFPROCESSOR_H_
#define MTFPROCESSOR_H_

#include "Processor.h"
#include "Tester.h"
#include "../Headers/Elements.h"

#include <string>
#include <list>
using std::string;
using std::list;
namespace Tools {

class MTFProcessorFactory;

class MTFProcessor : Processor {
  friend class MTFProcessorFactory;
 public:
  virtual ~MTFProcessor();
  virtual void Proceed(int id, bool learn = false);
  virtual int GetPenalty();
  using Processor::identifier;
  using Processor::user_id;

 private:
  MTFProcessor(int id, string identifier);
  // Penalty counter
  Tester penalty_counter_;
  // Element list
  list<shared_ptr<Base::Element> > element_list;
};

} /* namespace Tools */

#endif /* MTFPROCESSOR_H_ */
