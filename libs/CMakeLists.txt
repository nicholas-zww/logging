# Get all .cpp files in the libs directory
file(GLOB LIB_SOURCES "*.cpp")

#include(FetchContent)

#FetchContent_Declare(
    #spdlog
    #GIT_REPOSITORY https://github.com/gabime/spdlog.git
#)

#FetchContent_MakeAvailable(spdlog)

#FetchContent_GetProperties(spdlog)
#if(NOT spdlog_POPULATED)
  #FetchContent_Populate(spdlog)
#endif()

message(${spdlog_SOURCE_DIR}/include)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${spdlog_SOURCE_DIR}/include
)

#add_definitions(-DMAX_BUFFER_SIZE=${BUFFER_SIZE})
add_compile_definitions(
    SPDLOG_ENABLE_SYSLOG
)

add_library(${PROJECT_NAME}  ${LIB_SOURCES})

target_link_libraries(${PROJECT_NAME} pthread)
