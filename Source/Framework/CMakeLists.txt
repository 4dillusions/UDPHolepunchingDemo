project(Framework)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(WIN_LIBS ws2_32)
endif()

add_library(Framework
    IpV4Address.cpp
    IpV4Address.h
    MessageHelper.cpp
    MessageHelper.h
    Net.h
    ${CMAKE_SYSTEM_NAME}/Net.cpp
    ${CMAKE_SYSTEM_NAME}/NetworkSystemPlatform.h
    NetworkSystem.h
    SocketAddress.cpp
    ${CMAKE_SYSTEM_NAME}/SocketAddressPlatform.cpp
    SocketAddress.h
    UDPSocket.cpp
    ${CMAKE_SYSTEM_NAME}/UDPSocketPlatform.cpp
    UDPSocket.h)

target_link_libraries(Framework PRIVATE ${WIN_LIBS})

target_include_directories(Framework PUBLIC ..)
target_include_directories(Framework PUBLIC ../Framework/${CMAKE_SYSTEM_NAME})
