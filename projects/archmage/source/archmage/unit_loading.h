#pragma once

#include <string>
#include "Library.h"

namespace archmage {

  Unit &load_unit_from_string(const std::string &json, Library &library);
  Unit &load_project(const std::string &filename, Library &library);
  Unit &load_unit_from_file(const std::string &path, Library &library);
  void reference_dependency(const std::string &name, Library &library);
}