cmake_minimum_required(VERSION 3.10)
project(zappy)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wno-write-strings")
set(CMAKE_CXX_STANDARD 17)
find_package (Threads)

include_directories(include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(zappy_ai src/Main.cpp include/zappy_network.h src/AINetworkController.cpp include/AINetworkController.h src/AIManager.cpp include/AIManager.h src/AIPlayer.cpp include/AIPlayer.h src/AINetworkClient.cpp include/AINetworkClient.h src/MapObject.cpp src/MapObject.h src/Map.cpp src/Map.h)
target_link_libraries(zappy_ai zappy_network)

target_link_libraries (zappy_ai ${CMAKE_THREAD_LIBS_INIT})