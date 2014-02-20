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
  vector<shared_ptr<Tools::Processor> >& Query(string algorithm_name);
  vector<shared_ptr<Tools::Processor> >& Query();
  vector<string> QueryKeys();
 private:
  vector<shared_ptr<Tools::Processor> > table_;
  map<int, vector<shared_ptr<Tools::Processor> > > id_table_;
  map<string, vector<shared_ptr<Tools::Processor> > > name_table_;
};

} /* namespace Base */

#endif /* DATABASE_H_ */
