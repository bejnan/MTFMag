#pragma once

#include "../headers/data_managment.h"

namespace Utils {

class EventListener {
public:
	virtual ~EventListener() { }
	virtual void handleEvent(Base::Result result) = 0;
};

} /* namespace Tools */
