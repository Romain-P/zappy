//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_edi_t *deserialize_edi(char **args)
{
    packet_edi_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->egg);
    return (packet);
}