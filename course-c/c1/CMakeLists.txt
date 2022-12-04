cmake_minimum_required(VERSION 3.17)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} CXX)

#set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach ()