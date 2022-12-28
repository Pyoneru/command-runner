#pragma once

#include <nlohmann/json.hpp>
#include <memory>

#include "Config.h"
#include "CommandMapper.h"

using json = nlohmann::json;

namespace cr{
    /*
     * Map Config model to json and the opposite.
     */
    class ConfigMapper {
    private:
        std::shared_ptr<cr::CommandMapper> commandMapper;

    public:
        ConfigMapper(std::shared_ptr<cr::CommandMapper> &commandMapper);


        json toJson(Config &config);
        Config toObject(json &json);
    };
}