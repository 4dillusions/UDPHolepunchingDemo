cmake_minimum_required(VERSION 3.20)

project(Server CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Server Source/Main.cpp)
target_link_libraries(Server PRIVATE Framework)
target_include_directories(Server PRIVATE ../Framework/Source)
target_include_directories(Server PRIVATE ../Framework/Source/${CMAKE_SYSTEM_NAME})