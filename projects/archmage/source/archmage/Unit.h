#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Version.h"

namespace archmage {

  class Unit_Reference;

  class Unit {
      std::string name;
      std::string url;
      std::string path;
      std::vector<Unit_Reference> dependencies;
      std::vector<Unit *> dependents;

  public:
      Unit(const std::string &name) : name(name) {}

      void add_dependency(Unit &dependency, std:: shared_ptr< Version_Range> &version_range) {
        dependencies.push_back({dependency, version_range});
        dependency.dependents.push_back(this);
      }

      const std::string &get_name() const {
        return name;
      }

      const std::vector<Unit_Reference> &get_dependencies() const {
        return dependencies;
      }

      const std::vector<Unit *> &get_dependents() const {
        return dependents;
      }
  };

  class Unit_Reference {
      Unit &unit;
      std::shared_ptr<Version_Range> version;

  public:
      Unit_Reference(Unit &unit, std::shared_ptr<Version_Range> &version) :
        unit(unit), version(version) {}
  };
}