cmake_minimum_required(VERSION 3.10)
project(Unittest)

SET(GTEST_LIBRARY "/Users/jefklak/CLionProjects/googletest-release-1.8.0/googletest")
# reset linker flags; ARM + GTest doesn't work
SET(CMAKE_EXE_LINKER_FLAGS "${BASE_CMAKE_LINK_FLAGS}")
add_definitions(-DCODE_COMPILED_AS_PART_OF_TEST)

include_directories(${GTEST_LIBRARY}/include)

add_executable(unittest maintest.cpp gbatest.cpp spritetest.cpp ../src/engine/sprites/sprite.cpp ../src/engine/allocator.cpp scenetest.cpp allocatortest.cpp)
target_link_libraries(unittest ${GTEST_LIBRARY}/build/libgtest.a ${GTEST_LIBRARY}/build/libgtest_main.a)
