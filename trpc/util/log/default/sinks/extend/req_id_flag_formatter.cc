//
//
// Tencent is pleased to support the open source community by making tRPC available.
//
// Copyright (C) 2023 THL A29 Limited, a Tencent company.
// All rights reserved.
//
// If you have downloaded a copy of the tRPC source code from Tencent,
// please note that tRPC source code is licensed under the  Apache 2.0 License,
// A copy of the Apache 2.0 License is included in this file.
//
//


#include "trpc/util/log/default/sinks/extend/req_id_flag_formatter.h"

#include "trpc/server/server_context.h"
#include "spdlog/details/fmt_helper.h"

namespace trpc {

void ReqIdFlagFormatter::format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) {

  //::trpc::ServerContextPtr ctx = ::trpc::GetLocalServerContext();  
  //uint32_t filter_id = 65535;
  //auto req_id_ptr = ctx->GetFilterData<spdlog::string_view_t>(filter_id);
  //if (req_id_ptr != NULL) {
  //  spdlog::details::fmt_helper::append_string_view(*req_id_ptr, dest);
  //}
  spdlog::string_view_t test_req_id("1a93db6f430eccfbf83a992ca509f1e2");
  spdlog::details::fmt_helper::append_string_view(test_req_id, dest);
  return;
}

std::unique_ptr<spdlog::custom_flag_formatter> ReqIdFlagFormatter::clone() const
{
    return spdlog::details::make_unique<ReqIdFlagFormatter>();
}

}
