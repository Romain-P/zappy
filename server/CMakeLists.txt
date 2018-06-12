cmake_minimum_required(VERSION 3.10)
project(zappy C)

include_directories(include)
set(CMAKE_C_STANDARD 99)

add_executable(zappy_server include/zappy.h include/linked_list.h include/network.h include/network_epoll.h include/stderr.h include/util.h src/main.c src/shared/util.c src/shared/network_server.c src/shared/network_epoll.c src/shared/network_client.c src/shared/linked_list.c src/player.c src/network/packet_handler.c src/network/client_handler.c src/protocol/msg_example.c src/protocol/msz.c src/protocol/bct_tile.c src/protocol/bct_all_tile.c src/protocol/tna.c src/arguments/get_arguments.c include/arguments.h include/protocol.h)