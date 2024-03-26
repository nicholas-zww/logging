project(logger)

# Get all .cpp files in the libs directory
file(GLOB LIB_SOURCES "*.cpp")

# Add all source files in the libs directory to a library target
add_library(${PROJECT_NAME}  ${LIB_SOURCES})

# Add include directories for the library
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
)

 include(FetchContent)
 FetchContent_Declare(
     spdlog
     GIT_REPOSITORY https://github.com/gabime/spdlog.git
 )
 FetchContent_MakeAvailable(spdlog)

target_link_libraries(${PROJECT_NAME})
