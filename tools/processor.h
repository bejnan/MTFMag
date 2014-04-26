#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <string>

using std::string;

namespace Tools {
/**
 * Wrapper of algorithm to use it in real problem.
 * Processor is kind of adapter for DataCollector to
 * make algorithm useful to process notifications coded in data input.
 * @see Base::DataCollector
 */
class Processor {
 public:
  /**
   * Initialize user identifier (source of notifications) and algorithm identifier (algorithm name)
   * for data output
   * @param user_id Identifier of user who uses contact list (source of notifications)
   * @param algorithm_identifier Name of algorithm Processor is containing
   */
  Processor(int user_id, string algorithm_identifier);

  /**
   * Default destructor. Nothing to handle
   */
  virtual ~Processor();

  /**
   * Main method of Processor and all project.
   * By this method DataCollector uses algorithms and
   * examines their efficiency
   * @param user_id Identifier of friend chosen by user (source of notification). Method should be used for
   * source of notification the same as Processor represent.
   * @param learn Flag for penalty counter. Algorithm could have time to "learn" user choices and then no penalty is given.
   */
  virtual void Proceed(int user_id, bool learn = false) {  } ;

  /**
   * Returns penalty "earned" by algorithm. Details depends on penalty counter, but
   * main idea is that penalty is as big as far is user on friend list (algorithm ordered list of elements).
   * @see Tester
   * @see Algorithms::Algorithm
   * @return Sum of all penalties given to algorithm
   */
  virtual int GetPenalty() {
    return 0;
  }

  /**
   * Getter of algorithm name
   * @return Name of algorithm Processor represents
   */
  string algorithm_identifier() {
    return algorithm_identifier_;
  }

  /**
   * Getter of user identifier whose choices Processor "analyze"
   * @return Identifier of user (source of notifications)
   */
  int user_id() {
    return user_id_;
  }

 private:
  const int user_id_;         /**< Identifier of user */
  const string algorithm_identifier_; /**< Name (identifier)
                          of algorithm Processor uses */
};

} /* namespace Tools */

#endif /* ABSTRACTPROCESSOR_H_ */
