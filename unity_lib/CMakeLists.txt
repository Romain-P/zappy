cmake_minimum_required(VERSION 3.10)
project(zappy C)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_VISIBILITY_PRESET hidden)
include_directories(include)

add_library(zappy_network SHARED src/client_handler.c src/zappy_network.c include/zappy_network.h src/shared/linked_list.c src/shared/network_client.c src/shared/network_epoll.c include/network_epoll.h include/network.h include/stderr.h src/shared/util.c include/util.h include/linked_list.h include/protocol.h src/shared/network_connector.c src/packet_handler.c include/lib.h src/protocol/msz.c src/protocol/tna.c src/protocol/bct.c src/protocol/pnw.c src/protocol/ppo.c src/protocol/plv.c src/protocol/pin.c src/protocol/pex.c src/protocol/pbc.c src/protocol/pie.c src/protocol/pfk.c src/protocol/pdr.c)