/*
 * FileDataProvider.h
 *
 *  Created on: Feb 13, 2014
 *      Author: Jakub Banaszewski
 */

#ifndef FILEDATAPROVIDER_H_
#define FILEDATAPROVIDER_H_

#include "data_provider.h"
#include<cstdio>
#include<cstring>
#include<sstream>

using std::stringstream;

namespace Base {
/**
 * Class provides data read from input file.
 * It implements DataProvider interface.
 * It reads input file given by path in constructor
 * line by line.
 */
class FileDataProvider : public DataProvider {
 public:

  /**
   * Constructor opens file pointed by given path.
   * Important note! Read lines are empty after initialization.
   * To read first line method GoToNextLine have to be called.
   * @param file_path Absolute path to source file
   */
  FileDataProvider(string file_path);

  /**
   * Default destructor closes file.
   */
  virtual ~FileDataProvider();
  virtual const DataProvider::DataInputLine GetActualLine();
  virtual const DataProvider::DataInputLine GetLineBefore();
  virtual void GoToNextLine();

 private:
  const string file_path_; /**< Path to source file    */
  string actual_line_; /**< Last read line         */
  string line_before_; /**< Line read before       */
  FILE* input_file_; /**< Pointer to opened file */
};

} /* namespace Tree */

#endif /* FILEDATAPROVIDER_H_ */
