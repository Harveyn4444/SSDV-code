cmake_minimum_required(VERSION 3.10)
project(TX_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Absolute path to the CC1101 library
set(CC1101_LIB_PATH "/home/tilly/github/SSDV-code/Radio/libraries/CC1101")

# Create static library from the correct source file
add_library(CC1101 STATIC
    "${CC1101_LIB_PATH}/cc1100_raspi.cpp"
    "${CC1101_LIB_PATH}/cc1100_raspi.h"
)

# Include headers
target_include_directories(CC1101 PUBLIC "${CC1101_LIB_PATH}")

# Add your executable
add_executable(tx_example "${CMAKE_CURRENT_SOURCE_DIR}/tx_example.cpp")

# Link the library and wiringPi
target_link_libraries(tx_example PRIVATE CC1101 wiringPi)
