cmake_minimum_required(VERSION 3.16)

# Attempt to get generator via .cmake file
include(cmake/ninja.cmake)

# Include vcpkg toolchain file.
include(cmake/vcpkg.cmake)

# Place build output to build/bin directory
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin/")

# Project name and language
project (Experiment
        LANGUAGES CXX)

# 3rd Party libaries being used by this project/executable/library
find_package(fmt)

# Create executable
add_executable(cpptst)
# Add sources to above executable
target_sources(cpptst
    PRIVATE
        main.cpp)
# Compile using specified features
target_compile_features(cpptst
    PRIVATE
        cxx_std_17)
# Link with 3rd Party libraries
target_link_libraries(cpptst
    PRIVATE
        fmt::fmt)
