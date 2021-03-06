// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "wml/paths.h"

#include <unistd.h>

#include "wml/paths.h"

namespace wml {
namespace paths {

std::pair<bool, std::string> GetExecutableDirectoryPath() {
  const int path_size = 255;
  char path[path_size] = {0};
  auto read_size = ::readlink("/proc/self/exe", path, path_size);
  if (read_size == -1) {
    return {false, ""};
  }
  return {true, wml::paths::GetDirectoryName(
                    std::string{path, static_cast<size_t>(read_size)})};
}

}  // namespace paths
}  // namespace wml
