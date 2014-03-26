/*
 * MTFProcessor.h
 *
 *  Created on: Mar 2, 2014
 *      Author: kuba
 */

#ifndef MTFPROCESSOR_H_
#define MTFPROCESSOR_H_

#include "processor.h"
#include "tester.h"
#include "../headers/elements.h"

#include <string>
#include <list>
using std::string;
using std::list;
namespace Tools {

// Forward definition of MTFProcessor factory
class MTFProcessorFactory;

/*
 * MTFProcessor is Processor based on simple MTF (Move To Front) algorithm.
 * It uses simples penalty counter, that is Tester class.
 */
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
