#include_directories(../libtins/gtest-1.7.0/include ../libtins/gtest-1.7.0)
include_directories(../lib/googletest-release-1.6.0/include ../lib/googletest-release-1.6.0)


add_executable(presence-test
        FirstTest.cpp
        db/LevelDBConfigTest.cpp
        scanner/arpscannerTest.cpp
        scanner/arpTest.cpp
        tins/arpmonitorTest.cpp)


target_link_libraries(presence-test presence_lib)
target_link_libraries(presence-test gtest gtest_main)
