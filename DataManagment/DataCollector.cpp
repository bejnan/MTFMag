/*
 * DataCollector.cpp
 *
 *  Created on: Feb 13, 2014
 *      Author: kuba
 */

#include "DataCollector.h"

namespace Base {

DataCollector::DataCollector(DataProvider& data_input)
    : data_input_(data_input) {
}

DataCollector::~DataCollector() {
}

//TODO

void DataCollector::AddProccessor(Tools::Proccessor proc) {

}
void DataCollector::RunTurns(int turn_amount) {

}

} /* namespace Tree */
