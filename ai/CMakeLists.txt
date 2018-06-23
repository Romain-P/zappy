cmake_minimum_required(VERSION 3.10)
project(zappy)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wno-write-strings")
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(zappy_ai src/Main.cpp include/zappy_network.h src/AIController.cpp include/AIController.h src/AINetworkCommands.cpp include/AINetworkCommands.h src/AIManager.cpp include/AIManager.h src/AIPlayer.cpp src/AIPlayer.h)
target_link_libraries(zappy_ai zappy_network)