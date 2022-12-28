#include "command-runner/Command.h"

cr::Command::Command(const cr::Command &command) {
    this->name = command.name;
    this->shell = command.shell;
    this->command = command.command;
    if(command.next != nullptr){
        this->next = std::move(next);
    }
}

cr::Command::Command(const std::string &name, const std::string &shell, const std::string &command, std::unique_ptr<Command> &next){
    this->name = name;
    this->shell = shell;
    this->command = command;
    this->next = std::move(next);
}

std::string cr::Command::getName(){
    return name;
}

std::string cr::Command::getShell(){
    return shell;
}

std::string cr::Command::getCommand(){
    return command;
}

std::unique_ptr<cr::Command>& cr::Command::getNextCommand(){
    return next;
}

bool cr::Command::hasNextCommand(){
    return next != nullptr;
}
