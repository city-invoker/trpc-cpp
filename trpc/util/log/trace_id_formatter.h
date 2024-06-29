// copyright skylanwei 2023-11-18

#ifndef TRPC_APP_TRACE_TRACE_ID_FORMATTER_H_
#define TRPC_APP_TRACE_TRACE_ID_FORMATTER_H_

#include "spdlog/pattern_formatter.h"

namespace trpc {
namespace app {

class TraceIdFormatter : public spdlog::custom_flag_formatter {
public:
    void format(const spdlog::details::log_msg &, const std::tm &, spdlog::memory_buf_t &dest) override;

    std::unique_ptr<custom_flag_formatter> clone() const override;
};

}
}


#endif // TRPC_APP_TRACE_TRACE_ID_FORMATTER_H_
