cmake_minimum_required(VERSION 3.12.0)
project(cpp-cmake-structure-for-gmock)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
PUBLIC
classes)

add_subdirectory(classes)