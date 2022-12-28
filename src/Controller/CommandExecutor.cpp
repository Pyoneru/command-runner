#include "command-runner/CommandExecutor.h"
#include "command-runner/Logger.h"
#include "fmt/core.h"

#include <iostream>

#include "nlohmann/json.hpp"
#include <fstream>

#define CONFIG_FILENAME "cr_filename.json"

using json = nlohmann::json;

cr::CommandExecutor::CommandExecutor(std::shared_ptr<cr::ConfigMapper> &configMapper) {
    this->configMapper = configMapper;
}

void cr::CommandExecutor::executeCommand(std::string &target, std::unique_ptr<Config> &config) {

    if(target == "init"){

        std::unique_ptr<cr::Command> next(nullptr);
        cr::Command command{
                "build",
                "powershell",
                "cmake --build .",
                next
        };

        std::vector<cr::Command> commands{command};
        cr::Config cfg("powershell", commands);

        json data = this->configMapper->toJson(cfg);

        // check if file exists
        std::ifstream fileExists(CONFIG_FILENAME);
        if(fileExists.good()){
            LOG_WARNING(fmt::format("File '{}' already exists!", CONFIG_FILENAME));
            fileExists.close();
        }else{
            // save the file
            std::ofstream file(CONFIG_FILENAME);
            file << std::setw(4) << data << std::endl;
            file.close();
            LOG_DEBUG(fmt::format("File '{}' has been created!", CONFIG_FILENAME));
        }

    }else{
        std::vector<cr::Command> commands = config->getCommands();
        auto oCommand = std::find_if(commands.begin(), commands.end(), [&target](cr::Command &cmd){
            return cmd.getName() == target;
        });

        if(oCommand == commands.end()){
            LOG_ERROR(fmt::format("Cannot find command named '{}'", target));
            return;
        }

        cr::Command command = *oCommand;
        execute(config->getDefaultShell() , command);
    }

}

void cr::CommandExecutor::execute(const std::string& defaultShell, cr::Command &command) {


    std::string shell = "";

    if(!command.getShell().empty()){
        shell = command.getShell();
    }else if(!defaultShell.empty()){
        shell = defaultShell;
    }

    LOG_INFO(fmt::format("{} | COMMAND: {}",
                         !shell.empty() ? "SHELL: " + shell : "",
                         command.getCommand()));

    std::system(fmt::format("{shell} {command}",
                       fmt::arg("shell", shell),
                       fmt::arg("command", command.getCommand())).c_str()
                       );

    if(command.hasNextCommand()){
        execute(defaultShell, *command.getNextCommand());
    }
}
