// copyright skylanwei 2024-06-29

#ifndef TRPC_UTIL_LOG_MSG_NO_FORMATTER_H_
#define TRPC_UTIL_LOG_MSG_NO_FORMATTER_H_

#include "spdlog/pattern_formatter.h"

namespace trpc {

class MsgNoFormatter : public spdlog::custom_flag_formatter {
public:
    void format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) override;

    std::unique_ptr<custom_flag_formatter> clone() const override;
};

} // trpc


#endif // TRPC_UTIL_LOG_MSG_NO_FORMATTER_H_
