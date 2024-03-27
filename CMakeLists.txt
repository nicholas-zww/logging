cmake_minimum_required(VERSION 3.12)
project(logger)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
)

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
  FetchContent_Populate(spdlog)
endif()

message(${spdlog_SOURCE_DIR}/include)

add_subdirectory(libs)
add_subdirectory(demo)
