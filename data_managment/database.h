/*
 * Database.h
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include <map>
#include <vector>
#include <memory>
#include "../headers/tools.h"

using std::map;
using std::vector;
using std::shared_ptr;

namespace Base {
/**
 * This class split responsibility of storage Processors
 * with using Processor. User of Processors is DataCollector.
 * Database store, manages and gives access to Processor for DataCollector
 * by id or algorithms name.
 * ProcessorFactory classes responsible for creating Processors are stored
 * in DataCollector. Important! Database class have no outside memory. All it
 * stores is put there during runtime. After runtime all elements are removed
 * from memory. There should be only one instance of class in program.
 */
class Database {
 public:
  /**
   * Default constructor
   */
  Database();
  /**
   * Default destructor
   */
  virtual ~Database();

  /**
   * Method to add new Processor into "Database", in this case private vector.
   * There should be no other processor with the same id AND algorithms name.
   * @param processor Pointer to Processor to add
   */
  void AddToBase(shared_ptr<Tools::Processor> processor);

  /**
   * Return Processors for users with given id.
   * Every processor should represent different algorithm.
   * @param id Identifier of requested user
   * @return Collection of pointers to Processor with given user identifier
   */
  vector<shared_ptr<Tools::Processor> >& Query(int id);

  /**
   * Returns Processors for algorithm with given name.
   * Every identifier from returned Processor should be unique.
   * @param algorithm_name Name of algorithm placed in processor
   * @return Collection of pointers to Processor using named algorithm
   */
  vector<shared_ptr<Tools::Processor> >& Query(string algorithm_name);

  /**
   * Return every Processor placed in this class.
   * @return Collection of pointers to Processor stored in instance of class
   */
  vector<shared_ptr<Tools::Processor> >& Query();

  /**
   * Returns every algorithm name stored in instance of class
   * @return Vector of algorithm names (strings)
   */
  vector<string> QueryAlgorithmNames();

  /**
   * Checker of user existence in instance of class
   * @param id Identifier of user
   * @return True if there is processor for user with given id
   */
  bool Exists(int id);
 private:

  /**
   * Data storage of all Processor
   * Used in Query without any parameter
   */
  vector<shared_ptr<Tools::Processor> > table_;

  /**
   * "Table" of Processors with id as key
   *  Used in Query with int parameter.
   */
  map<int, vector<shared_ptr<Tools::Processor> > > id_table_;

  /**
   * "Table" of Processors with algorithm name as key
   *  Used in Query with string parameter.
   */
  map<string, vector<shared_ptr<Tools::Processor> > > name_table_;
};

} /* namespace Base */

#endif /* DATABASE_H_ */
