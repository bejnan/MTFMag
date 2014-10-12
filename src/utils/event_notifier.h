#pragma once

#include "event_listener.h"
#include <vector>

namespace Utils {

class EventNotifier {
public:
	EventNotifier();
	void addListener(std::shared_ptr<EventListener> notifier);
	void removeListener(std::shared_ptr<EventListener> notifier);
	virtual ~EventNotifier();
private :
	std::vector<std::shared_ptr<EventListener> > listeners;
};

typedef std::shared_ptr<EventNotifier> EventNotifierPtr;

} /* namespace Utils */
