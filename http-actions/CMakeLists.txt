project(HttpActions)

file(GLOB SOURCES "class/*.cpp")
file(GLOB HEADERS "class/*.hpp")
find_package(CURL REQUIRED)

add_library(lib ${SOURCES} ${HEADERS})
add_executable(server server.cpp)
add_executable(client client.cpp)
target_link_libraries(server lib)
target_link_libraries(client lib)
target_link_libraries(client CURL::libcurl)
