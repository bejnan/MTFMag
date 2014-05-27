/*
 * Database.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#include "database.h"
#include "../headers/exceptions.h"

using std::pair;
using std::make_pair;

namespace Base {

Database::~Database() {

}

Database::Database() {

}

void Database::AddToBase(shared_ptr<Tools::Processor> processor) {
  if (id_table_.find(processor->user_id()) == id_table_.end()) {
    id_table_.insert(
        make_pair(processor->user_id(),
                  vector<shared_ptr<Tools::Processor> >()));
  }
  id_table_[processor->user_id()].push_back(processor);

  if (name_table_.find(processor->AlgorithmName()) == name_table_.end()) {
    name_table_.insert(
        make_pair(processor->AlgorithmName(),
                  vector<shared_ptr<Tools::Processor> >()));
  }
  name_table_[processor->AlgorithmName()].push_back(processor);
  table_.push_back(processor);
}

vector<shared_ptr<Tools::Processor> >& Database::Query(int id) {
  if (id_table_.find(id) != id_table_.end())
    return id_table_.at(id);
  throw Exception::InvalidIndexException(id);
}

vector<shared_ptr<Tools::Processor> >& Database::Query(string algorithm_name) {
  if (name_table_.find(algorithm_name) != name_table_.end())
    return name_table_.at(algorithm_name);
  throw Exception::InvalidNameException(algorithm_name);
}

vector<shared_ptr<Tools::Processor> >& Database::Query() {
  return table_;
}

vector<string> Database::QueryAlgorithmNames() {
  vector<string> names;
  map<string, vector<shared_ptr<Tools::Processor> > >::iterator name_iterator;
  for (name_iterator = name_table_.begin(); name_iterator != name_table_.end();
      name_iterator++) {
    names.push_back(name_iterator->first);
  }
  return names;
}

bool Database::Exists(int id) {
  return (id_table_.find(id) != id_table_.end());
}

void Database::ClearDatabase() {
   table_.clear();
   id_table_.clear();
   name_table_.clear();
}

} /* namespace Base */
