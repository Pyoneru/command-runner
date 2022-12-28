#include "command-runner/CommandReader.h"
#include "command-runner/CommandExecutor.h"
#include "command-runner/Logger.h"

int main(int argc, char *argv[]){
    if(argc > 1) {
        std::shared_ptr<cr::CommandMapper> commandMapper;
        std::shared_ptr<cr::ConfigMapper> configMapper = std::make_shared<cr::ConfigMapper>(commandMapper);
        cr::CommandReader commandReader(configMapper);
        std::unique_ptr<cr::Config> config = commandReader.readConfigFile();
        cr::CommandExecutor executor(configMapper);
        std::string target(argv[1]);
        executor.executeCommand(target, config);
    }
    return 0;
}