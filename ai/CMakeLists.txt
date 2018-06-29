cmake_minimum_required(VERSION 3.10)
project(zappy)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wno-write-strings")
set(CMAKE_CXX_STANDARD 17)
find_package (Threads)

include_directories(include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(zappy_ai src/Main.cpp include/zappy_network.h src/network/AINetworkController.cpp include/network/AINetworkController.h src/AIManager.cpp include/AIManager.h src/AIPlayer.cpp include/AIPlayer.h src/network/AINetworkClient.cpp include/network/AINetworkClient.h src/network/AIData.cpp include/network/AIData.h include/Types.h src/ai/AbstractAI.cpp include/AbstractAI.h src/ai/BasicAI.cpp include/BasicAI.h)
target_link_libraries(zappy_ai zappy_network)

target_link_libraries (zappy_ai ${CMAKE_THREAD_LIBS_INIT})