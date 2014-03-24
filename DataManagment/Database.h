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
/**
 * Container of Processor elements.
 * Collect Processors by id or algorithms
 */
class Database {
 public:
  Database();
  virtual ~Database();
  //Add Processor to collection
  void AddToBase(shared_ptr<Tools::Processor> processor);
  // Get all Processors with given id
  vector<shared_ptr<Tools::Processor> >& Query(int id);
  // Get all Processors with given algorithm name
  vector<shared_ptr<Tools::Processor> >& Query(string algorithm_name);
  // Get all Processors
  vector<shared_ptr<Tools::Processor> >& Query();
  // Get all algorithm names
  vector<string> QueryKeys();
  // Returns true if database contains id
  bool Exists(int id);
 private:
  // Table of all Processors
  vector<shared_ptr<Tools::Processor> > table_;
  // Map between id and Processors
  map<int, vector<shared_ptr<Tools::Processor> > > id_table_;
  // Map between algorithm names and Processors
  map<string, vector<shared_ptr<Tools::Processor> > > name_table_;
};

} /* namespace Base */

#endif /* DATABASE_H_ */
