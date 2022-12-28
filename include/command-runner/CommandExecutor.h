#pragma once
#include <memory>
#include "Config.h"
#include "ConfigMapper.h"

namespace cr{
    class CommandExecutor{
    private:
        std::shared_ptr<cr::ConfigMapper> configMapper;
    public:
        CommandExecutor(std::shared_ptr<cr::ConfigMapper> &configMapper);
        /*
         * If target equals "init" then generate sample file 'cr_config.json'
         * Otherwise, run command defined in the config file if exists.
         */
        void executeCommand(std::string &target, std::unique_ptr<Config> &config);

    private:
        /*
         * execute commands (the command and their next commands)
         */
        void execute(const std::string& defaultShell, cr::Command &command);
    };

}