#include "logger.h"

std::shared_ptr<spdlog::async_logger> Logger::m_async_logger;

Logger::~Logger() {
    if (m_async_logger) {
        spdlog::shutdown();
    }
}

std::shared_ptr<spdlog::logger> Logger::getLogger() {

    if (!m_async_logger) {
        // Create a syslog sink
        auto m_syslog_sink = std::make_shared<spdlog::sinks::syslog_sink>();

        // Set logging level
        m_syslog_sink->set_level(spdlog::level::trace); // Set syslog level to trace to allow all levels

        // Configure the logger to use asynchronous logging
        spdlog::init_thread_pool(8192, 1); // Initialize thread pool with 8192 message queue size and 1 thread
        m_async_logger = std::make_shared<spdlog::async_logger>("async_syslog", syslog_sink, spdlog::thread_pool(), spdlog::async_overflow_policy::block);

        // Set logging level for async logger
        m_async_logger->set_level(spdlog::level::trace); // Set logger level to trace to allow all levels

        // Enable rotation of log files
        m_syslog_sink->set_rotate(true); // Enable rotation
        m_syslog_sink->set_rotate_size(1048576); // Set max size to 1MB
        m_syslog_sink->set_rotate_on_open(true); // Rotate on open

        // Register the async logger
        spdlog::register_logger(m_async_logger);
    }

    return m_async_logger;
}

