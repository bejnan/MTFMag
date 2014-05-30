#ifndef DATACOLLECTOR_H_
#define DATACOLLECTOR_H_

#include "../data_providers.h"
#include "../database.h"
#include "../data_outputs.h"
#include "../results.h"
#include "../../headers/tools.h"
#include "../../headers/algorithms.h"

#include <sstream>
#include <algorithm>
#include <memory>
#include <vector>

using std::accumulate;
using std::stringstream;
using std::stringbuf;
using std::vector;
using std::shared_ptr;
using std::pair;
using std::make_pair;

namespace Base {

/**
 * Class responsible for flow of data.
 * Supports processors (algorithms in JudgeCollector) with data and
 * print results.
 */
class DataCollector {
 public:

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

  DataCollector(shared_ptr<DataProvider> data_input,
                shared_ptr<DataOutput> data_output);

  ~DataCollector();

  shared_ptr<vector<DataInputLine> > ReadInputLines(int turn_amount);

  void PrintResults(int turn_amount, shared_ptr<vector<Result> > results);

 private:
  shared_ptr<DataProvider> data_input_; /**< Source of data to proceed */
  shared_ptr<DataOutput> data_output_; /**< Pointer to result printer */

};

} /* namespace Tree */

#endif /* DATACOLLECTOR_H_ */
