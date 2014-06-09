#ifndef DATAPROVIDER_H_
#define DATAPROVIDER_H_

#include <string>

using std::string;

namespace Base {
/**
 * Interface for data providers. Data provider should
 * return single line of input containing all elements :
 * - type of interaction
 * - timestamp
 * - sender id
 * - receiver id
 *
 * It is important to give access to single line multiple times (for multiple objects)
 */
class DataProvider {
 public:

  /**
   * Structure describing single input line.
   * Contains all elements needed in program.
   * All it's values are constant and initialized
   * by constructor.
   */
  struct DataInputLine {
    const int interaction_type_;
    const int timestamp_;
    const int sender_id_;
    const int receiver_id_;

    DataInputLine(int interaction_type, int timestamp, int sender_id,
                  int receiver_id)
        : interaction_type_(interaction_type),
          timestamp_(timestamp),
          sender_id_(sender_id),
          receiver_id_(receiver_id) {
    }
  };
  /**
   * Empty destuctor
   */
  virtual ~DataProvider() {
  }

  /**
   * Returns string with reading of actual input line.
   * @return Every string should contain line with 4 numbers
   * separated by whitespace
   */
  virtual const DataInputLine GetActualLine() = 0;

  /**
   * Returns string with reading of input line before
   * @return Every string should contain line with 4 numbers
   * separated by whitespace
   */
  virtual const DataInputLine GetLineBefore() = 0;

  /**
   * Switches reading to next input line.
   * Line before should be set to actual line (before reading)
   */
  virtual void GoToNextLine() = 0;
};

}

#endif
