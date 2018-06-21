#ifndef ZAPPY_LIBRARY_H
#define ZAPPY_LIBRARY_H

#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

#if defined(_MSC_VER)
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
#endif

#define PACKET_HEADER   char const *cmd
#define PACKED  __attribute__((__packed__))

typedef struct packet_example_s packet_example_t;
typedef struct packet_msz_s packet_msz_t;
typedef struct packet_bct_tile_s packet_bct_tile_t;
typedef struct packet_mct_s packet_mct_t;
typedef struct packet_tna_s packet_tna_t;
typedef struct packet_pnw_s packet_pnw_t;
typedef struct packet_ppo_s packet_ppo_t;
typedef struct packet_plv_s packet_plv_t;
typedef struct packet_pin_s packet_pin_t;
typedef struct packet_pex_s packet_pex_t;
typedef struct packet_pbc_s packet_pbc_t;
typedef struct packet_pic_s packet_pic_t;
typedef struct packet_pie_s packet_pie_t;
typedef struct packet_pfk_s packet_pfk_t;
typedef struct packet_pdr_s packet_pdr_t;
typedef struct packet_pgt_s packet_pgt_t;
typedef struct packet_pdi_s packet_pdi_t;
typedef struct packet_enw_s packet_enw_t;
typedef struct packet_eht_s packet_eht_t;
typedef struct packet_ebo_s packet_ebo_t;
typedef struct packet_edi_s packet_edi_t;
typedef struct packet_sgt_s packet_sgt_t;
typedef struct packet_sst_s packet_sst_t;
typedef struct packet_seg_s packet_seg_t;
typedef struct packet_smg_s packet_smg_t;
typedef struct packet_suc_s packet_suc_t;
typedef struct packet_sbp_s packet_sbp_t;
typedef struct packet_team_s packet_team_t;
typedef struct packet_forward_s packet_forward_t;
typedef struct packet_turn_s packet_turn_t;
typedef struct packet_inventory_s packet_inventory_t;

struct PACKED packet_msz_s {
    PACKET_HEADER;
    size_t x;
    size_t y;
};

struct PACKED packet_bct_tile_s {
    PACKET_HEADER;
    size_t x;
    size_t y;
    size_t q0;
    size_t q1;
    size_t q2;
    size_t q3;
    size_t q4;
    size_t q5;
    size_t q6;
};

struct PACKED packet_mct_s {
    PACKET_HEADER;
};

struct PACKED packet_tna_s {
    PACKET_HEADER;
    char name[1024];
};

struct PACKED packet_pnw_s {
    PACKET_HEADER;
    size_t player_number;
    size_t x;
    size_t y;
    size_t orientation;
    size_t level;
    char name_team[1024];
};

struct PACKED packet_ppo_s {
    PACKET_HEADER;
    size_t player_number;
    size_t x;
    size_t y;
    size_t orientation;
};

struct PACKED packet_plv_s {
    PACKET_HEADER;
    size_t player_number;
    size_t level;
};

struct PACKED packet_pin_s {
    PACKET_HEADER;
    size_t player_number;
    size_t x;
    size_t y;
    size_t q0;
    size_t q1;
    size_t q2;
    size_t q3;
    size_t q4;
    size_t q5;
    size_t q6;
};

struct PACKED packet_pex_s {
    PACKET_HEADER;
    size_t player_number;
};

struct PACKED packet_pbc_s {
    PACKET_HEADER;
    size_t player_number;
    char message[1024];
};

struct PACKED packet_pic_s {
    PACKET_HEADER;
    size_t x;
    size_t y;
    size_t incantation_level;
    size_t player_nb1;
    size_t player_nb2;
};

struct PACKED packet_pie_s {
    PACKET_HEADER;
    size_t x;
    size_t y;
    size_t result;
};

struct PACKED packet_pfk_s {
    PACKET_HEADER;
    size_t player_number;
};

struct PACKED packet_pdr_s {
    PACKET_HEADER;
    size_t player_number;
    size_t ressource;
};

struct PACKED packet_pgt_s {
    PACKET_HEADER;
    size_t player_number;
    size_t ressource;
};

struct PACKED packet_pdi_s {
    PACKET_HEADER;
    size_t player_number;
};

struct PACKED packet_enw_s {
    PACKET_HEADER;
    size_t egg;
    size_t player_number;
    size_t x;
    size_t y;
};

struct PACKED packet_eht_s {
    PACKET_HEADER;
    size_t egg;
};

struct PACKED packet_ebo_s {
    PACKET_HEADER;
    size_t egg;
};

struct PACKED packet_edi_s {
    PACKET_HEADER;
    size_t egg;
};

struct PACKED packet_sgt_s {
    PACKET_HEADER;
    size_t time;
};

struct PACKED packet_sst_s {
    PACKET_HEADER;
    size_t time;
};

struct PACKED packet_seg_s {
    PACKET_HEADER;
    char team[1024];
};

struct PACKED packet_smg_s {
    PACKET_HEADER;
    char message[1024];
};

struct PACKED suc_s {
    PACKET_HEADER;
};

struct PACKED sbp_s {
    PACKET_HEADER;
};

struct PACKED packet_forward_s {
    PACKET_HEADER;
};

struct PACKED packet_inventory_s {
    PACKET_HEADER;
    char result[2048];
};

struct PACKED packet_turn_s {
    PACKET_HEADER;
    char orientation[6];
};

struct PACKED packet_team_s {
    PACKET_HEADER;
    char team[1024];
    int status;
};

typedef struct network_handlers_s network_handlers_t;
typedef int session_t;

struct network_handlers_s {
    void (*on_connect)(session_t id);
    void (*on_disconnect)(session_t id);
    void (*on_map_size_reply)(session_t id, packet_msz_t *);
    void (*on_tile_content_reply)(session_t id, packet_bct_tile_t *);
    void (*on_team_name_reply)(session_t id, packet_tna_t *);
    void (*on_player_position_update)(session_t id, packet_ppo_t *);
    void (*on_player_level_update)(session_t id, packet_plv_t *);
    void (*on_player_inventory_update)(session_t id, packet_pin_t *);
    void (*on_player_connected)(session_t id, packet_pnw_t *);
    void (*on_player_expulsed)(session_t id, packet_pex_t *);
    void (*on_broadcast)(session_t id, packet_pbc_t *);
    void (*on_server_broadcast)(session_t id, packet_smg_t *);
    void (*on_player_cast_start)(session_t id, packet_pic_t *);
    void (*on_player_cast_end)(session_t id, packet_pie_t *);
    void (*on_player_lay_self)(session_t id, packet_pfk_t *);
    void (*on_player_lay)(session_t id, packet_enw_t *);
    void (*on_player_drop)(session_t id, packet_pdr_t *);
    void (*on_player_collect)(session_t id, packet_pgt_t *);
    void (*on_player_death)(session_t id, packet_pdi_t *);
    void (*on_egg_hatching)(session_t id, packet_eht_t *);
    void (*on_egg_hatching_death)(session_t id, packet_edi_t *);
    void (*on_timeunit_reply)(session_t id, packet_sgt_t *);
    void (*on_timeunit_modif_reply)(session_t id, packet_sst_t *);
    void (*on_game_end)(session_t id, packet_seg_t *);
    void (*on_unknown_command)(session_t id, packet_suc_t *);
    void (*on_command_param_wrong)(session_t id, packet_sbp_t *);
};

EXPORT bool zappy_init_connector(char *address, uint16_t port, bool thread_sync, network_handlers_t *handlers);
EXPORT session_t zappy_new_connection();
EXPORT void zappy_sync_poll();
EXPORT void send_packet(session_t id, void *msg);

#endif