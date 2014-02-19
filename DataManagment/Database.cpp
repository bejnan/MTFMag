/*
 * Database.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "Database.h"

namespace Base {

Database::Database() {

}

Database::~Database() {

}

void Database::AddToBase(shared_ptr<Tools::Processor> processor) {
  table[processor->user_id()] = processor;
}

vector<shared_ptr<Tools::Processor> >& Database::Query(int id) {
  if (table.find(id) != table.end())
    return table.at(id);
  return vector<shared_ptr<Tools::Processor> >();
}

} /* namespace Base */
