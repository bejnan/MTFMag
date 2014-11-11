#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "../utils/event_notifier.h"
#include <stdexcept>

class EventListenerStub : public Utils::EventListener {
public :
	EventListenerStub(Base::Result eventToHandle) :
			m_eventToHandle(eventToHandle) { }

	void handleEvent(Base::Result result) {
		if (! (result == m_eventToHandle))
		{
			throw new std::runtime_error("Wrong result to handle");
		}
	}

private :
	Base::Result m_eventToHandle;

};


BOOST_AUTO_TEST_SUITE(ResultCollectorTest)

BOOST_AUTO_TEST_CASE(EventNotifierNotifyTest) {
	Base::Result result("a", 1, 1, 1);
	auto listener = std::make_shared<EventListenerStub>(result);
	Utils::EventNotifier notifier;
	notifier.addListener(listener);
	BOOST_CHECK_NO_THROW(notifier.notify(result));
}



BOOST_AUTO_TEST_SUITE_END();
 /* namespace Utils */
