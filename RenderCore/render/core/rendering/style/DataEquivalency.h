// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WEEX_UIKIT_CORE_RENDERING_STYLE_DATAEQUIVALENCY_H_
#define WEEX_UIKIT_CORE_RENDERING_STYLE_DATAEQUIVALENCY_H_

#include "render/wtf/OwnPtr.h"
#include "render/wtf/RefPtr.h"

namespace blink {

template <typename T>
bool dataEquivalent(const T* a, const T* b) {
  if (a == b)
    return true;
  if (!a || !b)
    return false;
  return *a == *b;
}

template <typename T>
bool dataEquivalent(const RefPtr<T>& a, const RefPtr<T>& b) {
  return dataEquivalent(a.get(), b.get());
}

template <typename T>
bool dataEquivalent(const OwnPtr<T>& a, const OwnPtr<T>& b) {
  return dataEquivalent(a.get(), b.get());
}

}  // namespace blink

#endif  // WEEX_UIKIT_CORE_RENDERING_STYLE_DATAEQUIVALENCY_H_
