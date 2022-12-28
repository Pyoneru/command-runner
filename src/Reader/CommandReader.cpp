#include "command-runner/CommandReader.h"
#include "command-runner/Logger.h"


#include <fstream>
#include "fmt/core.h"
#include <memory>
#include "nlohmann/json.hpp"

#define CONFIG_FILENAME "cr_filename.json"

using json = nlohmann::json;

cr::CommandReader::CommandReader(std::shared_ptr<ConfigMapper> &configMapper) {
    this->configMapper = configMapper;
}

std::unique_ptr<cr::Config> cr::CommandReader::readConfigFile() {
    std::ifstream file(CONFIG_FILENAME);

    if (file.good()) {
        std::unique_ptr<cr::Config> config(nullptr);
        try {
            json data = json::parse(file);

            cr::Config cfg = this->configMapper->toObject(data);

            config = std::make_unique<Config>(&cfg);

        }catch(json::exception &e){
            LOG_ERROR(fmt::format("Cannot parse the config file\n{}", e.what()));
        }
        file.close();
        return config;

    } else {
        LOG_ERROR(fmt::format("Cannot open the file'{}'", CONFIG_FILENAME));
        return nullptr;
    }
}
