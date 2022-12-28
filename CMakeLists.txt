cmake_minimum_required(VERSION 3.14)

project(CommandRunner)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
        nlohmann
        GIT_REPOSITORY https://github.com/nlohmann/json.git
)
FetchContent_MakeAvailable(nlohmann)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

add_executable(cr
        src/main.cpp
        src/Controller/CommandExecutor.cpp
        src/Controller/Logger.cpp
        src/Mapper/ConfigMapper.cpp
        src/Mapper/CommandMapper.cpp
        src/Model/Config.cpp
        src/Model/Command.cpp
        src/Reader/CommandReader.cpp)

target_include_directories(cr PUBLIC include)

target_link_libraries(cr nlohmann_json::nlohmann_json fmt::fmt)