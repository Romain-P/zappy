cmake_minimum_required(VERSION 3.10)
project(zappy C)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_VISIBILITY_PRESET hidden)

include_directories(include)
find_package (Threads)

add_library(zappy_network SHARED src/client_handler.c src/zappy_network.c src/shared/linked_list.c src/shared/network_client.c src/shared/network_epoll.c include/network_epoll.h include/network.h include/stderr.h src/shared/util.c include/util.h include/linked_list.h include/protocol.h src/shared/network_connector.c src/packet_handler.c include/lib.h src/protocol/msz.c src/protocol/tna.c src/protocol/bct.c src/protocol/pnw.c src/protocol/ppo.c src/protocol/plv.c src/protocol/pin.c src/protocol/pex.c src/protocol/pbc.c src/protocol/pie.c src/protocol/pfk.c src/protocol/pdr.c src/protocol/pgt.c src/protocol/pdi.c src/protocol/enw.c src/protocol/eht.c src/protocol/ebo.c src/protocol/edi.c src/protocol/sgt.c src/protocol/sst.c src/protocol/seg.c src/protocol/smg.c src/protocol/suc.c src/protocol/sbp.c src/protocol/pic.c src/protocol/welcome.c src/protocol/message.c src/protocol/look.c src/protocol/broadcast.c src/protocol/inventory.c src/protocol/connect_number.c)
