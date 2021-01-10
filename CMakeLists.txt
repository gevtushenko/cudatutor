cmake_minimum_required(VERSION 3.17)
project(cudatutor CXX CUDA)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.69.0 COMPONENTS system filesystem program_options REQUIRED)
configure_file(src/config.cpp.in config.cpp)

find_package(Threads REQUIRED)

add_executable(cudatutor
        main.cpp
        src/command.cpp
        src/answer.cpp
        include/command.h
        include/answer.h
        include/config.h
        ${CMAKE_CURRENT_BINARY_DIR}/config.cpp
        include/question.h 
        src/question.cpp 
        include/questions.h
        src/questions.cpp

        include/questions/basics/vec_add.h
        src/questions/basics/vec_add.cpp
        src/questions/basics/vec_add_kernel.cu
        src/questions/helpers/array_functions.cu
        src/questions/basics/mem_copy_kernel.cu
        include/questions/basics/mem_copy_01.h
        include/questions/basics/mem_copy_02.h
        src/questions/basics/mem_copy_01.cpp
        src/questions/basics/mem_copy_02.cpp
        include/questions/helpers/array_functions.h
        include/arguments.h
        src/arguments.cpp
        )
target_link_libraries(cudatutor PRIVATE ${Boost_LIBRARIES} Threads::Threads ${CMAKE_DL_LIBS})
target_include_directories(cudatutor PRIVATE ${Boost_INCLUDE_DIR} ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES} include)
