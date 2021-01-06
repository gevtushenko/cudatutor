cmake_minimum_required(VERSION 3.17)
project(cudatutor)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.75.0 COMPONENTS system filesystem REQUIRED)

add_executable(cudatutor main.cpp include/command.h src/command.cpp)
target_link_libraries(cudatutor PRIVATE ${Boost_LIBRARIES})
target_include_directories(cudatutor PRIVATE ${Boost_INCLUDE_DIR} include)