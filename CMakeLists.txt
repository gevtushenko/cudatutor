cmake_minimum_required(VERSION 3.17)
project(cudatutor)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.75.0 COMPONENTS system filesystem REQUIRED)
message(${Boost_INCLUDE_DIR})
configure_file(src/config.cpp.in config.cpp)

add_executable(cudatutor
        main.cpp
        src/command.cpp
        src/answer.cpp
        include/command.h
        include/answer.h
        include/config.h
        ${CMAKE_CURRENT_BINARY_DIR}/config.cpp
        include/question.h src/question.cpp src/questions/basics/vec_add.cpp include/questions.h src/questions.cpp)
target_link_libraries(cudatutor PRIVATE ${Boost_LIBRARIES})
target_include_directories(cudatutor PRIVATE ${Boost_INCLUDE_DIR} include)