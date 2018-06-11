cmake_minimum_required(VERSION 3.10)
project(lan001)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

include_directories(presence)

add_subdirectory(presence)
add_subdirectory(presence-test)

include_directories(include)
link_directories(lib/leveldb)

add_executable(lan001 main.cpp)
target_link_libraries(lan001 presence_lib leveldb)
