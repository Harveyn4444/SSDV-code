cmake_minimum_required(VERSION 3.13)
project(cc1101)

set(CMAKE_CXX_STANDARD 11)

# Add RadioLib submodule
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../libraries/RadioLib
                 ${CMAKE_CURRENT_BINARY_DIR}/RadioLib-build)

add_executable(cc1101 main.cpp)

# Link against RadioLib and lgpio
target_link_libraries(cc1101 PRIVATE RadioLib lgpio)
