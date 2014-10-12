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
struct Result {

  /**
   * Constructor which initialize most important parameters.
   * @param algorithm_name Name of the algorithm that produce result.
   * @param source_id User that was a source of notifications.
   * @param penalty Penalty counted for user till this moment.
   * @param timestamp Moment of user choice (notification).
   * @param comment Additional description of result (Default empty).
   */
  Result(string algorithm_name, int source_id, int penalty,
         int timestamp, string comment = "");

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

  const string algorithm_name_;

  const int source_id_;

  const int overall_penalty_;

  const int timestamp_;

  const string comment_;

};

} /* namespace Base */

#endif /* RESULT_H_ */
