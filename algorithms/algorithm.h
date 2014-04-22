/*
 * algorithm.h
 *
 *  Created on: Apr 22, 2014
 *      Author: kuba
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

namespace Base {

class Algorithm {
 public :
  virtual ~Algorithm() { };

  virtual void NotifyContent(int user_id) = 0;

  virtual void NotifyContent(int user_id, int notification_count) = 0;

  virtual int GetContentPosition(int user_id) = 0;

  virtual void AddElement(int user_id) = 0;
};

}

#endif /* ALGORITHM_H_ */
