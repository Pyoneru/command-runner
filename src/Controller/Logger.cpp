#include "command-runner/Logger.h"
#include "fmt/core.h"

void cr::Logger::LogError(std::string msg) {
    fmt::print("|ERROR|\t{}\n", msg);
}

void cr::Logger::LogWarning(std::string msg) {
    fmt::print("|WARNING|\t{}\n", msg);
}

void cr::Logger::LogInfo(std::string msg) {
    fmt::print("|INFO|\t{}\n", msg);
}

void cr::Logger::LogDebug(std::string msg) {
    fmt::print("|DEBUG|\t{}\n", msg);
}
