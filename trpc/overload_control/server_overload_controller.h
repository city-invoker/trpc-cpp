// Copyright (c) 2024, Tencent Inc.
// All rights reserved.

#pragma once

#include <memory>
#include <string>

#include "trpc/server/server_context.h"

namespace trpc::overload_control {

/// @brief Base class of overload controller.
class ServerOverloadController {
 public:
  virtual ~ServerOverloadController() = default;

  /// @brief Name of this controller.
  virtual std::string Name() = 0;

  /// @brief Initialize controller.
  ///        You can allocate resources or start thread as controller need.
  /// @return bool true: succ; false: failed
  virtual bool Init() { return true; }

  /// @brief Whether this request should be scheduled to handle.
  ///        When reject this request, you should also set status with error code TRPC_SERVER_OVERLOAD_ERR
  ///        into context.
  /// @param context server context.
  /// @return bool true: this request will be handled; false: this request should be rejected.
  virtual bool BeforeSchedule(const ServerContextPtr& context) = 0;

  /// @brief After this request being sheduled. At this point, it may be handled or rejected.
  //         You can check status from context to distinguish these 2 scenes when implement.
  /// @param context server context.
  /// @return bool true: succ; false: failed.
  virtual bool AfterSchedule(const ServerContextPtr& context) = 0;

  /// @brief Stop controller. One can stop the thread execution of controller implemetation.
  virtual void Stop() {}

  /// @brief Destroy resources of controller.
  virtual void Destroy() {}
};

using ServerOverloadControllerPtr = std::shared_ptr<ServerOverloadController>;

}  // namespace trpc::overload_control
