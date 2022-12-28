#pragma once
#include <vector>
#include <memory>

#include "Config.h"
#include "ConfigMapper.h"


namespace cr{
    class CommandReader{
    private:
        std::shared_ptr<ConfigMapper> configMapper;
    public:
        CommandReader(std::shared_ptr<ConfigMapper> &configMapper);

        /*
         * Read the config file with defined commands.
         */
        std::unique_ptr<Config> readConfigFile();
    };
}