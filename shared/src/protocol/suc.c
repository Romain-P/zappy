//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>

packet_suc_t *deserialize_suc(char **args) {
    packet_suc_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    return (packet);
}