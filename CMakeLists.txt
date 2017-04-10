cmake_minimum_required(VERSION 3.6)

project(twoThreadWithInit)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS system filesystem thread REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES main.cpp threadNET.cpp threadDB.cpp globalFuncs.h globalFuncs.cpp)

add_executable(twoThreadWithInit ${SOURCE_FILES})

target_link_libraries(twoThreadWithInit ${Boost_LIBRARIES})
