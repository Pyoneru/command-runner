#pragma once

#include <nlohmann/json.hpp>

#include "Command.h"

using json = nlohmann::json;

namespace cr{
    /*
     * Map command model to json and the opposite.
     */
    class CommandMapper{
    public:
        json toJson(Command &command);
        Command toObject(json &json);
    };
}