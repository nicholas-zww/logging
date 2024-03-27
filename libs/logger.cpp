#include <iostream>
#include <fstream>
#include <string>

#include "logger.h"

#include <spdlog/sinks/syslog_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

std::shared_ptr<spdlog::async_logger> Logger::m_async_logger;
std::string Logger::logger_name;

Logger::Logger() {
#if 0
    if (logger_name.empty())
        logger_name = getProcessName();
#endif
}

Logger::~Logger() {
    if (m_async_logger) {
        spdlog::drop_all();
    }
}

std::string Logger::getProcessName() {
    std::ifstream cmdline("/proc/self/cmdline");
    std::string processName;
    if (cmdline.is_open()) {
        std::getline(cmdline, processName, '\0');
        // Extracting the actual process name from the full path
        size_t pos = processName.rfind('/');
        if (pos != std::string::npos)
            processName = processName.substr(pos + 1);
        cmdline.close();
    }
    return processName;
}

std::shared_ptr<spdlog::logger> Logger::getLogger() {

    if (!m_async_logger) {

        // Create a syslog sink
        auto m_syslog_sink = std::make_shared<spdlog::sinks::syslog_sink>();
        //auto m_stdout_sink = std::make_shared<spdlog::sinks::stdout_sink_mt >();
        //auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("mylog.txt", 1024*1024*10, 3);

        // Set logging level
        m_syslog_sink->set_level(spdlog::level::trace); // Set syslog level to trace to allow all levels

        std::vector<spdlog::sink_ptr> sinks {m_syslog_sink};

        // Configure the logger to use asynchronous logging
        m_async_logger = std::make_shared<spdlog::async_logger>(logger_name, sinks.begin(), sinks.end(), 1024);

        // Set logging level for async logger
        //m_async_logger->set_level(spdlog::level::trace); // Set logger level to trace to allow all levels
#ifdef DEBUG
        m_async_logger->set_level(spdlog::level::debug); // Set logger level to trace to allow all levels
#else
        m_async_logger->set_level(spdlog::level::info); // Set logger level to trace to allow all levels
#endif

        // Register the async logger
        spdlog::register_logger(m_async_logger);
    }

    return m_async_logger;
}

