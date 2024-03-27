cmake_minimum_required(VERSION 3.12)
project(demo_logger)

# Add the main executable
file(GLOB PROJECT_SRC "*.cpp")

add_executable(${PROJECT_NAME} ${PROJECT_SRC})


# Add include directories for the library
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../libs/inc
    ${spdlog_SOURCE_DIR}/include
)

# Link the main program with the library target
target_link_libraries(${PROJECT_NAME}
    logger
)
