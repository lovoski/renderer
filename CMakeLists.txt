cmake_minimum_required(VERSION 3.20)

project(renderer)

file(GLOB SRC_FILES src/*.cpp)

# library for window creation
add_subdirectory(libs/pixie)

include_directories(
  libs/pixie
  includes)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE pixie)
