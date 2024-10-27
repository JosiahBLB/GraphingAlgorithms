cmake_minimum_required(VERSION 3.14)
project(GraphAlgorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create a symlink to the compile_commands.json in the project root
add_custom_target(
    create_symlink ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
)

# enable googletest
set(DOWNLOAD_EXTRACT_TIMESTAMP TRUE) # ensures rebuild on url change
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
if(MSVC)
    set(gtest_force_shared_crt ON BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)
enable_testing()

add_subdirectory(src)