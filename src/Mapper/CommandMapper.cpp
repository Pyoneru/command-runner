#include "command-runner/CommandMapper.h"

#define PROPERTY_NAME "name"
#define PROPERTY_SHELL "shell"
#define PROPERTY_COMMAND "command"
#define PROPERTY_NEXT "next"


json cr::CommandMapper::toJson(cr::Command &command) {
    json output;

    output[PROPERTY_NAME] = command.getName();
    output[PROPERTY_SHELL] = command.getShell();
    output[PROPERTY_COMMAND] = command.getCommand();

    if(command.hasNextCommand()){
        json next = toJson(*command.getNextCommand());
        output[PROPERTY_NEXT] = next;
    }

    return output;
}

cr::Command cr::CommandMapper::toObject(json &json) {
    std::string name = json[PROPERTY_NAME].is_string() ? json[PROPERTY_NAME] : "";
    std::string shell = json[PROPERTY_SHELL].is_string() ? json[PROPERTY_SHELL] : "";
    std::string command = json[PROPERTY_COMMAND].is_string() ? json[PROPERTY_COMMAND] : "";

    std::unique_ptr<cr::Command> next(nullptr);
    if(json[PROPERTY_NEXT] != nullptr){
        cr::Command nextCommand = toObject(json[PROPERTY_NEXT]);
        next.reset(&nextCommand);
    }

    return cr::Command{name, shell, command, next};
}
