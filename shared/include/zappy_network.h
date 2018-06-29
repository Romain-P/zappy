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

#define PACKET_HEADER   char cmd[15]
#define PACKED

typedef struct packet_example_s packet_example_t;
typedef struct packet_msz_s packet_msz_t;
typedef struct packet_welcome_s packet_welcome_t;
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
typedef struct packet_look_s packet_look_t;
typedef struct packet_broadcast_s packet_broadcast_t;
typedef struct packet_connect_number_s packet_connect_number_t;
typedef struct packet_message_s packet_message_t;
typedef struct packet_inventory_s packet_inventory_t;
typedef struct waiting_s waiting_t;

struct waiting_s {
    void (*handler)(uint32_t, void *);
    uint32_t client_id;
    void *packet;
};

struct PACKED packet_welcome_s {
    PACKET_HEADER;
};

struct PACKED packet_msz_s {
    PACKET_HEADER;
    uint32_t x;
    uint32_t y;
};

struct PACKED packet_bct_tile_s {
    PACKET_HEADER;
    uint32_t x;
    uint32_t y;
    uint32_t q0;
    uint32_t q1;
    uint32_t q2;
    uint32_t q3;
    uint32_t q4;
    uint32_t q5;
    uint32_t q6;
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
    uint32_t player_number;
    uint32_t x;
    uint32_t y;
    uint32_t orientation;
    uint32_t level;
    char name_team[1024];
};

struct PACKED packet_ppo_s {
    PACKET_HEADER;
    uint32_t player_number;
    uint32_t x;
    uint32_t y;
    uint32_t orientation;
};

struct PACKED packet_plv_s {
    PACKET_HEADER;
    uint32_t player_number;
    uint32_t level;
};

struct PACKED packet_pin_s {
    PACKET_HEADER;
    uint32_t player_number;
    uint32_t x;
    uint32_t y;
    uint32_t q0;
    uint32_t q1;
    uint32_t q2;
    uint32_t q3;
    uint32_t q4;
    uint32_t q5;
    uint32_t q6;
};

struct PACKED packet_pex_s {
    PACKET_HEADER;
    uint32_t player_number;
};

struct PACKED packet_pbc_s {
    PACKET_HEADER;
    uint32_t player_number;
    char message[1024];
};

struct PACKED packet_pic_s {
    PACKET_HEADER;
    uint32_t x;
    uint32_t y;
    uint32_t incantation_level;
    uint32_t players_count;
    uint32_t players[100];
};

struct PACKED packet_pie_s {
    PACKET_HEADER;
    uint32_t x;
    uint32_t y;
    uint32_t result;
};

struct PACKED packet_pfk_s {
    PACKET_HEADER;
    uint32_t player_number;
};

struct PACKED packet_pdr_s {
    PACKET_HEADER;
    uint32_t player_number;
    uint32_t ressource;
};

struct PACKED packet_pgt_s {
    PACKET_HEADER;
    uint32_t player_number;
    uint32_t ressource;
};

struct PACKED packet_pdi_s {
    PACKET_HEADER;
    uint32_t player_number;
};

struct PACKED packet_enw_s {
    PACKET_HEADER;
    uint32_t egg;
    uint32_t player_number;
    uint32_t x;
    uint32_t y;
};

struct PACKED packet_eht_s {
    PACKET_HEADER;
    uint32_t egg;
};

struct PACKED packet_ebo_s {
    PACKET_HEADER;
    uint32_t egg;
};

struct PACKED packet_edi_s {
    PACKET_HEADER;
    uint32_t egg;
};

struct PACKED packet_sgt_s {
    PACKET_HEADER;
    uint32_t time;
};

struct PACKED packet_sst_s {
    PACKET_HEADER;
    uint32_t time;
};

struct PACKED packet_seg_s {
    PACKET_HEADER;
    char team[1024];
};

struct PACKED packet_smg_s {
    PACKET_HEADER;
    char message[1024];
};

struct PACKED packet_suc_s {
    PACKET_HEADER;
};

struct PACKED packet_sbp_s {
    PACKET_HEADER;
};

struct PACKED packet_message_s {
    PACKET_HEADER;
    uint32_t tile;
    char text[100];
};

struct PACKED packet_look_s {
    PACKET_HEADER;
    char data[2048];
};

struct PACKED packet_broadcast_s {
    PACKET_HEADER;
    char text[1024];
};

struct PACKED packet_connect_number_s {
    PACKET_HEADER;
    uint32_t value;
};


struct PACKED packet_inventory_s {
    PACKET_HEADER;
    char result[2048];
};

typedef struct gui_handlers_s gui_handlers_t;
typedef struct ai_handlers_s ai_handlers_t;
typedef uint32_t session_t;

struct gui_handlers_s {
    void (*on_connect)(session_t id);
    void (*on_disconnect)(session_t id);
    void (*on_welcome)(session_t id, packet_welcome_t *);
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

struct ai_handlers_s {
    void (*on_connect)(session_t id);
    void (*on_disconnect)(session_t id);
    void (*on_welcome)(session_t id, packet_welcome_t *);
    void (*on_look_reply)(session_t, packet_look_t *);
    void (*on_message_reply)(session_t, packet_message_t *);
    void (*on_connect_nummber_reply)(session_t, packet_connect_number_t *);
    void (*on_inventory_reply)(session_t, packet_inventory_t *);
    void (*on_unwrapped)(session_t id, char **packet);
};


EXPORT extern bool zappy_init_connector(char *address, uint16_t port, gui_handlers_t handlers, uint32_t timeout);
EXPORT extern bool zappy_init_connector_ai(char *address, uint16_t port, ai_handlers_t handlers, uint32_t timeout);
EXPORT extern session_t zappy_new_connection();
EXPORT extern void zappy_sync_poll();
EXPORT extern void send_packet(session_t id, void *msg);
EXPORT extern void send_unwrapped(session_t id, char *msg);

#endif