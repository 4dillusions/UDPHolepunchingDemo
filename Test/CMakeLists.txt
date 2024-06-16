project(Test)

add_executable(Test 
    Source/IpV4AddressTests.cpp
    Source/NetworkSystemTest.cpp
    Source/SocketAddressTests.cpp
    Source/UDPSocketTests.cpp
    Source/Main.cpp)

target_include_directories(Test PRIVATE ../thirdparty/Catch2/single_include)
target_link_libraries(Test PRIVATE Framework ${WIN_LIBS})