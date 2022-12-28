#include "command-runner/Config.h"

cr::Config::Config(const std::string &defaultShell, std::vector<Command> &commands) {
    this->defaultShell = defaultShell;
    this->commands = std::move(commands);
}

cr::Config::Config(cr::Config *pConfig) {
    this->defaultShell = pConfig->defaultShell;
    this->commands = pConfig->getCommands();
}


std::string cr::Config::getDefaultShell() {
    return defaultShell;
}

std::vector<cr::Command> cr::Config::getCommands() {
    return std::move(commands);
}

