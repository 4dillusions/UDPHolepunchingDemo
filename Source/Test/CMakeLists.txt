project(Test)

add_executable(${PROJECT_NAME} 
	IpV4AddressTests.cpp
    NetworkSystemTest.cpp
    SocketAddressTests.cpp
    UDPSocketTests.cpp
    Main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty/Catch2/single_include)
target_link_libraries(${PROJECT_NAME} PRIVATE Framework ${WIN_LIBS} Catch2::Catch2)

include(CTest)
include(${CMAKE_SOURCE_DIR}/thirdparty/Catch2/contrib/Catch.cmake)
catch_discover_tests(${PROJECT_NAME})
