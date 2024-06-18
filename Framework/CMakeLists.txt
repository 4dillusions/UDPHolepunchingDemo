project(Framework)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(WIN_LIBS ws2_32)
endif()

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

target_link_libraries(Framework PRIVATE ${WIN_LIBS})

target_include_directories(Framework PUBLIC Source)
target_include_directories(Framework PUBLIC Source/${CMAKE_SYSTEM_NAME})