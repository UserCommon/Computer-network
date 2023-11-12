cmake_minimum_required(VERSION 3.3)
project(prj2_3)

add_library(MessageLib Message.hpp Message.cc)

add_executable(server server.cc)
target_link_libraries(server MessageLib)

add_executable(client client.cc)
target_link_libraries(client MessageLib)

