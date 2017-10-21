cmake_minimum_required (VERSION 2.6)
project(Neuron)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
add_executable(neuron neuron.cpp network.cpp main.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(

target_link_libraries(
add_test(
