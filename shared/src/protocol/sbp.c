//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>

packet_sbp_t *deserialize_sbp(char **args) {
    packet_sbp_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    return (packet);
}