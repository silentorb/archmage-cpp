#include "Library.h"

namespace archmage {

  Unit *Library::get_unit_or_null(const std::string &name) const {
    if (units.count(name))
      return units[name].get();

    if (incomplete_units.count(name))
      return incomplete_units[name].get();

    return nullptr;
  }
}