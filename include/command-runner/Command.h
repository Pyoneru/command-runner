#pragma once
#include <string>
#include <vector>
#include <memory>

namespace cr{
    class Command{
        private:
        /*
         * Custom name of command
         */
        std::string name;
        /*
         * Shell, e.g.: powershell, cmd, wsl
         */
        std::string shell;
        /*
         * command line
         */
        std::string command;
        /*
         * Next command in order
         */
        std::unique_ptr<Command> next;

        public:

        Command(const Command &command);

        Command(const std::string &name, const std::string &shell, const std::string &command, std::unique_ptr<Command> &next);

        std::string getName();

        std::string getShell();

        std::string getCommand();

        std::unique_ptr<Command>& getNextCommand();

        bool hasNextCommand();

    };
}
