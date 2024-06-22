project(Server)
add_executable(Server Source/Main.cpp)
target_link_libraries(Server PRIVATE Framework)