cmake_minimum_required(VERSION 3.7)
project(presence)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/db/LevelDBConfig.cpp
        src/db/LevelDBConnector.cpp
        src/Base64.cpp
        src/stringhelper.cpp
        src/filehelper.cpp
        src/ReplaceAll.cpp
        src/filehelper.cpp
        src/LogAdapter.h
        src/functions.cpp)

set(SOURCE_FILES_MAIN
        ${SOURCE_FILES}
        )

include_directories(../include)
link_directories(../lib/leveldb ../lib/libnet ../lib/libtins)

add_library(presence_lib ${SOURCE_FILES_MAIN})
target_link_libraries(presence_lib leveldb net tins)
