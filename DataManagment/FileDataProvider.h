/*
 * FileDataProvider.h
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#ifndef FILEDATAPROVIDER_H_
#define FILEDATAPROVIDER_H_

#include "DataProvider.h"
#include<cstdio>
#include<cstring>

namespace Base {
/*
 * Class provides data read from input file
 */
class FileDataProvider : public DataProvider {
 public:
  // file_path - path to input file
  FileDataProvider(string file_path);
  virtual ~FileDataProvider();
  virtual string GetActualLine();
  virtual string GetLineBefore();
  virtual void GoToNextLine();
 private :
  const string file_path_;
  string actual_line_;
  string line_before_;
  FILE* input_file_;
};

} /* namespace Tree */

#endif /* FILEDATAPROVIDER_H_ */
