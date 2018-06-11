project(presence-test)


include_directories(../include)
link_directories(../lib/leveldb)

add_subdirectory(unit_test)
add_subdirectory(lib/googletest-release-1.6.0)
