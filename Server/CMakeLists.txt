cmake_minimum_required(VERSION 3.20)

project(Server CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(WIN_LIBS ws2_32)
endif()

add_executable(Server Source/Main.cpp)

target_link_libraries(Server PRIVATE Framework ${WIN_LIBS})
target_include_directories(Server PRIVATE ../Framework/Source)
target_include_directories(Server PRIVATE ../Framework/Source/${CMAKE_SYSTEM_NAME})