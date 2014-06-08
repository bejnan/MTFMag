#include "non_existing_element.h"

using std::to_string;
namespace Exception {

NonExistingElement::NonExistingElement(int id)
    : message_("Element with given identifier doesn't exists") {
  if (id != 0) {
    message_ += " : " + Utils::ToString(id);
  }
}

NonExistingElement::~NonExistingElement() {

}

} /* namespace Exception */
