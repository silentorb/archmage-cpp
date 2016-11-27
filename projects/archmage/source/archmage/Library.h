#pragma once

#include "Unit.h"
#include <memory>
#include <string>
#include <vector>
#include <map>

namespace archmage {

  class Unit_Source {
  public:
      virtual std::unique_ptr<Unit> get_unit(const std::string &name) = 0;
  };

  class Library {
      std::map<std::string, std::unique_ptr<Unit>> units;
      std::map<std::string, std::unique_ptr<Unit>> incomplete_units;

      Unit *get_unit_or_null(const std::string &name) const;
  };
}