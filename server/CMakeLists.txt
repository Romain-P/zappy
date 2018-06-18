cmake_minimum_required(VERSION 3.10)
project(zappy C)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")
include_directories(include)
set(CMAKE_C_STANDARD 99)

add_executable(zappy_server include/mouvement.h include/zappy.h include/map.h include/team.h include/linked_list.h include/network.h include/network_epoll.h include/stderr.h include/util.h src/main.c src/mouvement.c src/map/ressource.c src/map/init_map.c src/team.c src/shared/util.c src/shared/network_server.c src/shared/network_epoll.c src/shared/network_client.c src/shared/linked_list.c src/player.c src/network/packet_handler.c src/network/client_handler.c src/protocol/msg_example.c src/protocol/msz.c src/protocol/bct_tile.c src/protocol/bct_all_tile.c src/protocol/tna.c src/protocol/inventory.c src/protocol/pnw.c src/protocol/ppo.c src/protocol/plv.c src/protocol/turn.c src/protocol/pin.c src/protocol/pex.c src/protocol/pbc.c src/protocol/pic.c src/protocol/pie.c src/protocol/pfk.c src/protocol/pdr.c src/protocol/pgt.c src/protocol/pdi.c src/protocol/enw.c src/protocol/eht.c src/protocol/ebo.c src/protocol/edi.c src/protocol/sgt.c src/protocol/forward.c src/protocol/sst.c src/protocol/seg.c src/protocol/smg.c src/protocol/suc.c src/protocol/sbp.c src/protocol/team.c src/arguments/get_arguments.c include/arguments.h include/protocol.h src/time_handler.c)
