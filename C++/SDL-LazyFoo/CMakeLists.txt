cmake_minimum_required(VERSION 3.19)

project(sdl-lazyfoo)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(HEADERS
  lesson1/lesson1.hpp
  lesson2/lesson2.hpp
)

set(SOURCES
  lesson1/src/lesson1.cpp
  lesson2/src/lesson2.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC 
  lesson1
  lesson2)