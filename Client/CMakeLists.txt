project(Client)
add_executable(Client Source/Main.cpp)
target_link_libraries(Client PRIVATE Framework)