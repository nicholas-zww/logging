#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/syslog_sink.h>
#include <spdlog/async.h>

class Logger {
public:
    ~Logger();

private:
    static std::shared_ptr<spdlog::async_logger> m_async_logger;
};

#define LOG Logger::getLogger()
