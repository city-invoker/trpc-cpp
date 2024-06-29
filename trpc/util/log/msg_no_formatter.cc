#include "msg_no_formatter.h"

#include "trpc/server/server_context.h"
#include <spdlog/details/fmt_helper.h>

namespace trpc {

void MsgNoFormatter::format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) {

  auto context = ::trpc::GetLocalServerContext();
  if (context != nullptr) {
    spdlog::details::fmt_helper::append_string_view(context->GetMsgNo(), dest);
  }
}

std::unique_ptr<spdlog::custom_flag_formatter> MsgNoFormatter::clone() const {
  return spdlog::details::make_unique<MsgNoFormatter>();
}

} // trpc
