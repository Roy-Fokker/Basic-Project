cmake_minimum_required(VERSION 3.16)

# Include vcpkg toolchain file.
include(cmake/vcpkg.cmake)

# Include MSVC Settings file.
include(cmake/msvc_settings.cmake)

# Place build output to build/bin directory
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin/")

# Project name and language
project (Basic_Project
        LANGUAGES CXX)

# Project Configuration Interface
add_library(project_configuration INTERFACE)

# Compile using specified features
target_compile_features(project_configuration
    INTERFACE
        cxx_std_17)

# Load MSVC specific settings
set_msvc_project_configuration(project_configuration)


# 3rd Party libaries being used by this project/executable/library
find_package(fmt)

# Create executable
add_executable(cpptst)
# Add sources to above executable
target_sources(cpptst
    PRIVATE
        main.cpp)

# Link with 3rd Party libraries
target_link_libraries(cpptst
    PRIVATE
        project_configuration
        fmt::fmt)
