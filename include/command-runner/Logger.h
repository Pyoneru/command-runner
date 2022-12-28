#pragma once
#include <string>

#define LOG_ERROR(msg) cr::Logger::LogError(msg)
#define LOG_WARNING(msg) cr::Logger::LogWarning(msg)
#define LOG_INFO(msg) cr::Logger::LogInfo(msg)
#define LOG_DEBUG(msg) cr::Logger::LogDebug(msg)

namespace cr{
    /*
     * Simple logger
     */
    class Logger{
    public:
        static void LogError(std::string msg);
        static void LogWarning(std::string msg);
        static void LogInfo(std::string msg);
        static void LogDebug(std::string msg);
    };
}