#include <utility>

#include "command-runner/ConfigMapper.h"

#define PROPERTY_DEFAULT_SHELL "default-shell"
#define PROPERTY_COMMANDS "commands"

cr::ConfigMapper::ConfigMapper(std::shared_ptr<cr::CommandMapper> &commandMapper) {
    this->commandMapper = commandMapper;
}

json cr::ConfigMapper::toJson(cr::Config &config) {
    json output;

    output[PROPERTY_DEFAULT_SHELL] = config.getDefaultShell();

    std::vector<json> commands;
    for(auto &command : config.getCommands()){
        json jsonCommand = this->commandMapper->toJson(command);
        commands.push_back(jsonCommand);
    }
    output[PROPERTY_COMMANDS] = commands;

    return output;
}

cr::Config cr::ConfigMapper::toObject(json &json) {

    std::string defaultShell = json[PROPERTY_DEFAULT_SHELL].is_string() ? json[PROPERTY_DEFAULT_SHELL] : "";

    std::vector<cr::Command> commands;
    if(json[PROPERTY_COMMANDS] != nullptr){
        for(auto &jsonCommand : json[PROPERTY_COMMANDS]){
            cr::Command command = this->commandMapper->toObject(jsonCommand);
            commands.push_back(command);
        }
    }

    return cr::Config{defaultShell, commands};
}
