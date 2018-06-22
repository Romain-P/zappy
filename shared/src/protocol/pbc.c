//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <util.h>
#include <stdlib.h>
#include <string.h>

packet_pbc_t *deserialize_pbc(char **args)
{
    packet_pbc_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->player_number);
    strcpy(packet->message, args[1]);
    return (packet);
}
