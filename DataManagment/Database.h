/*
 * Database.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <map>
#include <vector>
#include <memory>
#include "../Headers/Tools.h"

using std::map;
using std::vector;
using std::shared_ptr;

namespace Base {

class Database {
 public:
  Database();
  virtual ~Database();
  void AddToBase(shared_ptr<Tools::Processor> processor);
  vector<shared_ptr<Tools::Processor> >& Query(int id);
 private:
  map<int, vector<shared_ptr<Tools::Processor> > > table;
};

} /* namespace Base */

#endif /* DATABASE_H_ */
