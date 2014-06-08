#ifndef RESULT_H_
#define RESULT_H_

#include "../../headers/tools.h"
#include "../../utils/utils.h"

#include<vector>
#include<memory>

using std::vector;
using std::string;
using std::shared_ptr;
using std::pair;

namespace Base {
/**
 * Container of all meaningful parameters representing algorithms result.
 * Additional role of this class is to make results readable and understandable.
 */
class Result {
 public:

  /**
   * Constructor which initialize most important parameters.
   * @param algorithm_name Name of the algorithm that produce result.
   * @param source_id User that was a source of notifications.
   * @param overal_penalty Penalty counted for user till this moment.
   * @param timestamp Moment of user choice (notification).
   * @param comment Additional description of result (Default empty).
   */
  Result(string algorithm_name, int source_id, int overall_penalty,
         int timestamp, string comment = "");

  /**
   * Constructor which initialize the same parameters, but uses pointer
   * do Tools::Processor to get needed values.
   * @param processor_ptr Pointer to Processor which analyse call (notification) that generated result.
   * @param timestamp Moment of notification (user choice).
   * @param comment Additional description of result (Default empty).
   */
  Result(shared_ptr<Tools::Processor> processor_ptr, int timestamp,
         string comment = "");

  /**
   * Empty destructor (nothing to handle).
   */
  virtual ~Result();

  /**
   * Returns description for columns.
   * @return Header line describing columns of results.
   */
  virtual string HeaderLine();

  /**
   * Returns result in readable form.
   * In child classes this method could return more detailed description.
   * In base class it return all properties values : <li>
   * <ul> Algorithm name
   * <ul> Source of notification (user id)
   * <ul> Time of notification (timestamp)
   * <ul> Overall penalty counted with last notification
   * </li>
   * @return Line of text with result and its description
   */
  virtual string ToString();

  /**
   * Getter of overall penalty property.
   * @return Value of penalty that was initialized in constructor.
   */
  const int GetOverallPenalty() const;

 protected:
  /**
   * Getter of algorithm name property.
   * @return Name of algorithm initialized in constructor.
   */
  const string& GetAlgorithmName() const;

  /**
   * Getter of comment property.
   * @return Comment of result initialized in constructor.
   */
  const string& GetComment() const;

  /**
   * Getter of source id property.
   * @return Id of sender of message (source of notification) initialized in constructor.
   */
  const int GetSourceId() const;

  /**
   * Getter of timestamp when notification took place.
   * @return Timestamp initialized in constructor with information when notification took place.
   */
  const int GetTimestamp() const;

 private:

  /** Name of algorithm property */
  const string algorithm_name_;

  /** Id of user that was source of notification */
  const int source_id_;

  /** Penalty counted by algorithm till this moment (including this notification)*/
  const int overall_penalty_;

  /** Timestamp of moment when notification took place */
  const int timestamp_;

  /** Comment to result */
  const string comment_;

};

} /* namespace Base */

#endif /* RESULT_H_ */
