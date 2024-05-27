cmake_minimum_required(VERSION 3.20)

project(Framework CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Framework PRIVATE Source/${CMAKE_SYSTEM_NAME})

add_library(Framework
    Source/IpV4Address.cpp
    Source/IpV4Address.h
    Source/MessageHelper.cpp
    Source/MessageHelper.h
    Source/Net.h
    Source/${CMAKE_SYSTEM_NAME}/Net.cpp
    Source/${CMAKE_SYSTEM_NAME}/NetworkSystemPlatform.h
    Source/NetworkSystem.h
    Source/SocketAddress.cpp
    Source/${CMAKE_SYSTEM_NAME}/SocketAddressPlatform.cpp
    Source/SocketAddress.h
    Source/UDPSocket.cpp
    Source/${CMAKE_SYSTEM_NAME}/UDPSocketPlatform.cpp
    Source/UDPSocket.h)