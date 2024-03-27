#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/async_logger.h>

class Logger {
public:
    Logger();
    ~Logger();
    static std::shared_ptr<spdlog::logger> getLogger();

private:
    static std::string logger_name;
    static std::shared_ptr<spdlog::async_logger> m_async_logger;
    static std::string getProcessName();
};

#define LOG(args...) Logger::getLogger()->debug(args)
#define LOGW(args...) Logger::getLogger()->warn(args)
#define LOGE(args...) Logger::getLogger()->error(args)
#define LOGI(args...) Logger::getLogger()->info(args)
#define LOGC(args...) Logger::getLogger()->critical(args)
