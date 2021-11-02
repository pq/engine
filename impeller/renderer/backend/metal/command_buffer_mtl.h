// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <Metal/Metal.h>

#include "flutter/fml/macros.h"
#include "impeller/renderer/command_buffer.h"

namespace impeller {

class CommandBufferMTL final : public CommandBuffer {
 public:
  CommandBufferMTL();

  // |CommandBuffer|
  ~CommandBufferMTL() override;

 private:
  friend class ContextMTL;

  id<MTLCommandBuffer> buffer_ = nullptr;
  bool is_valid_ = false;

  CommandBufferMTL(id<MTLCommandQueue> queue);

  // |CommandBuffer|
  bool IsValid() const override;

  // |CommandBuffer|
  void Commit(CompletionCallback callback) override;

  // |CommandBuffer|
  std::shared_ptr<RenderPass> CreateRenderPass(
      const RenderPassDescriptor& desc) const override;

  FML_DISALLOW_COPY_AND_ASSIGN(CommandBufferMTL);
};

}  // namespace impeller