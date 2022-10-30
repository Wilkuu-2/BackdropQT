# --------------------
#    CMakeLists 
#    
#    Copyright 2022 Wilkuu www.wilkuu.xyz 
#
# --------------------

cmake_minimum_required(VERSION 3.20)
# Project name 
project(BackdropQT VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets WebEngineWidgets WebEngine REQUIRED)

# Include the source folders
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Get all source files
file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.ui"
)

# Create executable
add_executable(BackdropQT ${all_SRCS})

target_link_libraries(BackdropQT PRIVATE Qt5::Core Qt5::Widgets Qt5::WebEngineWidgets Qt5::Gui Qt5::WebEngine)
