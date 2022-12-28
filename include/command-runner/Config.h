#pragma once
#include <string>
#include <vector>

#include "Command.h"

namespace cr{
    class Config{
        private:
        /*
         * Use default shell if it is not specified in a command.
         */
        std::string defaultShell;
        /*
         * Command list
         */
        std::vector<cr::Command> commands;

        public:
        Config(const std::string &defaultShell, std::vector<Command> &commands);
        Config(Config *pConfig);

        std::string getDefaultShell();

        std::vector<Command> getCommands();


    };
}