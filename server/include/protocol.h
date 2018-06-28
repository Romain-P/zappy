/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Protocol Header
*/

#ifndef ZAPPY_PROTOCOL_H
#define ZAPPY_PROTOCOL_H

	#include "zappy.h"

	typedef struct packet_example_s packet_example_t;
	typedef struct packet_msz_s packet_msz_t;
	typedef struct packet_bct_tile_s packet_bct_tile_t;
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
	typedef struct packet_left_s packet_left_t;
	typedef struct packet_right_s packet_right_t;
	typedef struct packet_inventory_s packet_inventory_t;
	typedef struct packet_look_s packet_look_t;
	typedef struct packet_broadcast_s packet_broadcast_t;
	typedef struct packet_connectnbr_s packet_connectnbr_t;
	typedef struct packet_fork_s packet_fork_t;
	typedef struct packet_eject_s packet_eject_t;
	typedef struct packet_take_s packet_take_t;
	typedef struct packet_set_s packet_set_t;
	typedef struct packet_incantation_s packet_incantation_t;
	
	struct __attribute__((__packed__)) packet_example_s {
		PACKET_HEADER;
		int64_t some;
		char str[100];
		int64_t shiet;
	};

	struct __attribute__((__packed__)) packet_msz_s {
		PACKET_HEADER;
		size_t x;
		size_t y;
	};

	struct __attribute__((__packed__)) packet_bct_tile_s {
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

	struct __attribute__((__packed__)) packet_tna_s {
		PACKET_HEADER;
		char name[1024];
	};

	struct __attribute__((__packed__)) packet_pnw_s {
		PACKET_HEADER;
		size_t player_number;
		size_t x;
		size_t y;
		size_t orientation;
		size_t level;
		char name_team[1024];
	};

	struct __attribute__((__packed__)) packet_ppo_s {
		PACKET_HEADER;
		size_t player_number;
		size_t x;
		size_t y;
		size_t orientation;
	};

	struct __attribute__((__packed__)) packet_plv_s {
		PACKET_HEADER;
		size_t player_number;
		size_t level;
	};

	struct __attribute__((__packed__)) packet_pin_s {
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

	struct __attribute__((__packed__)) packet_pex_s {
		PACKET_HEADER;
		size_t player_number;
	};

	struct __attribute__((__packed__)) packet_pbc_s {
		PACKET_HEADER;
		size_t player_number;
		char message[1024];
	};

	struct __attribute__((__packed__)) packet_pic_s {
		PACKET_HEADER;
		size_t x;
		size_t y;
		size_t incantation_level;
		size_t player_nb1;
		size_t player_nb2;
	};

	struct __attribute__((__packed__)) packet_pie_s {
		PACKET_HEADER;
		size_t x;
		size_t y;
		size_t result;
	};

	struct __attribute__((__packed__)) packet_pfk_s {
		PACKET_HEADER;
		size_t player_number;
	};

	struct __attribute__((__packed__)) packet_pdr_s {
		PACKET_HEADER;
		size_t player_number;
		size_t ressource;
	};

	struct __attribute__((__packed__)) packet_pgt_s {
		PACKET_HEADER;
		size_t player_number;
		size_t ressource;
	};

	struct __attribute__((__packed__)) packet_pdi_s {
		PACKET_HEADER;
		size_t player_number;
	};

	struct __attribute__((__packed__)) packet_enw_s {
		PACKET_HEADER;
		size_t egg;
		size_t player_number;
		size_t x;
		size_t y;
	};

	struct __attribute__((__packed__)) packet_eht_s {
		PACKET_HEADER;
		size_t egg;
	};

	struct __attribute__((__packed__)) packet_ebo_s {
		PACKET_HEADER;
		size_t egg;
	};

	struct __attribute__((__packed__)) packet_edi_s {
		PACKET_HEADER;
		size_t egg;
	};

	struct __attribute__((__packed__)) packet_sgt_s {
		PACKET_HEADER;
		size_t time;
	};

	struct __attribute__((__packed__)) packet_sst_s {
		PACKET_HEADER;
		size_t time;
	};

	struct __attribute__((__packed__)) packet_seg_s {
		PACKET_HEADER;
		char team[1024];
	};

	struct __attribute__((__packed__)) packet_smg_s {
		PACKET_HEADER;
		char message[1024];
	};

	struct __attribute__((__packed__)) packet_suc_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_sbp_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_forward_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_take_s {
		PACKET_HEADER;
		char node[1024];
	};

	struct __attribute__((__packed__)) packet_set_s {
		PACKET_HEADER;
		char node[1024];
	};

	struct __attribute__((__packed__)) packet_fork_s {
		PACKET_HEADER;
		egg_t *egg;
	};

	struct __attribute__((__packed__)) packet_incantation_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_eject_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_connectnbr_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_broadcast_s {
		PACKET_HEADER;
		char text[1024];
	};

	struct __attribute__((__packed__)) packet_look_s {
		PACKET_HEADER;
		size_t tile;
		int x;
		int y;
		size_t number;
		size_t level;
		size_t q0;
		size_t q1;
		size_t q2;
		size_t q3;
		size_t q4;
		size_t q5;
		size_t q6;
	};

	struct __attribute__((__packed__)) packet_inventory_s {
		PACKET_HEADER;
		char result[2048];
	};

	struct __attribute__((__packed__)) packet_left_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_right_s {
		PACKET_HEADER;
	};

	struct __attribute__((__packed__)) packet_team_s {
		PACKET_HEADER;
		char team[1024];
		int status;
	};

	void send_unwrapped(network_client_t *, char *);

	bool msg_example_handler(player_t *player, packet_example_t *msg);
	packet_example_t *msg_example_deserialize(char **args);
	void msg_example_serialize(packet_example_t *msg, list_t *buffer);

	// FORWARD COMMAND
	bool forward_handler(player_t *, packet_forward_t *);
	packet_forward_t *forward_deserialize(char **);
	void forward_serialize(packet_forward_t *, list_t *);

	// TAKE COMMAND
	bool take_handler(player_t *, packet_take_t *);
	packet_take_t *take_deserialize(char **);
	void take_serialize(packet_take_t *, list_t *);
	size_t get_id_ressource(char *);

	// SET COMMAND
	bool set_handler(player_t *, packet_set_t *);
	packet_set_t *set_deserialize(char **);
	void set_serialize(packet_set_t *, list_t *);

	// EJECT COMMAND
	bool eject_handler(player_t *, packet_eject_t *);
	packet_eject_t *eject_deserialize(char **);
	void eject_serialize(packet_eject_t *, list_t *);

	// FORK COMMAND
	bool fork_handler(player_t *, packet_fork_t *);
	packet_fork_t *fork_deserialize(char **);
	void fork_serialize(packet_fork_t *, list_t *);

	// FORK COMMAND
	bool incantation_handler(player_t *, packet_incantation_t *);
	packet_incantation_t *incantation_deserialize(char **);
	void incantation_serialize(packet_incantation_t *, list_t *);

	// RIGHT COMMAND
	bool right_handler(player_t *, packet_right_t *);
	packet_right_t *right_deserialize(char **);
	void right_serialize(packet_right_t *, list_t *);

	// LEFT COMMAND
	bool left_handler(player_t *, packet_left_t *);
	packet_left_t *left_deserialize(char **);
	void left_serialize(packet_left_t *, list_t *);

	// CONNECTNBR COMMAND
	bool connectnbr_handler(player_t *, packet_connectnbr_t *);
	packet_connectnbr_t *connectnbr_deserialize(char **);
	void connectnbr_serialize(packet_connectnbr_t *, list_t *);

	// BROADCAST COMMAND
	bool broadcast_handler(player_t *, packet_broadcast_t *);
	packet_broadcast_t *broadcast_deserialize(char **);
	void broadcast_serialize(packet_broadcast_t *, list_t *);

	// LOOK COMMAND
	bool look_handler(player_t *, packet_look_t *);
	packet_look_t *look_deserialize(char **);
	void look_serialize(packet_look_t *, list_t *);

	// IVENTORY COMMAND
	bool inventory_handler(player_t *, packet_inventory_t *);
	packet_inventory_t *inventory_deserialize(char **);
	void inventory_serialize(packet_inventory_t *, list_t *);
	void increment_inventory(player_t *, size_t);
	void set_ressource(player_t *, size_t);

	// MSZ COMMAND
	bool msz_handler(player_t *, packet_msz_t *);
	packet_msz_t *msz_deserialize(char **);
	void msz_serialize(packet_msz_t *, list_t *);

	// BCT COMMAND (One Tile)
	packet_bct_tile_t *bct_tile_deserialize(char **);
	bool bct_tile_handler(player_t *, packet_bct_tile_t *);
	void bct_tile_serialize(packet_bct_tile_t *, list_t *);
	void init_bct_tile_packet(packet_bct_tile_t *packet);
	void get_ressource_tile(size_t, packet_bct_tile_t *);

	// BCT COMMAND (All Tile)
	packet_bct_tile_t *bct_all_deserialize(char **);
	bool bct_all_handler(player_t *, packet_bct_tile_t *);
	void bct_all_serialize(packet_bct_tile_t *, list_t *);

	// TNA COMMAND
	packet_tna_t *tna_deserialize(char **);
	bool tna_handler(player_t *, packet_tna_t *);
	void tna_serialize(packet_tna_t *, list_t *);

	// PNW COMMAND
	packet_pnw_t *pnw_deserialize(char **);
	bool pnw_handler(player_t *, packet_pnw_t *);
	void pnw_serialize(packet_pnw_t *, list_t *);
	void send_pnw(player_t *);

	// PPO COMMAND
	packet_ppo_t *ppo_deserialize(char **);
	bool ppo_handler(player_t *, packet_ppo_t *);
	void ppo_serialize(packet_ppo_t *, list_t *);

	// PLV COMMAND
	packet_plv_t *plv_deserialize(char **);
	bool plv_handler(player_t *, packet_plv_t *);
	void plv_serialize(packet_plv_t *, list_t *);

	// PIN COMMAND
	packet_pin_t *pin_deserialize(char **);
	bool pin_handler(player_t *, packet_pin_t *);
	void pin_serialize(packet_pin_t *, list_t *);

	// PEX COMMAND
	packet_pex_t *pex_deserialize(char **);
	bool pex_handler(player_t *player, packet_pex_t *);
	void pex_serialize(packet_pex_t *, list_t *);

	// PBC COMMAND
	packet_pbc_t *pbc_deserialize(char **);
	bool pbc_handler(player_t *player, packet_pbc_t *);
	void pbc_serialize(packet_pbc_t *, list_t *);

	// PIC COMMAND
	packet_pic_t *pic_deserialize(char **);
	bool pic_handler(player_t *, packet_pic_t *);
	void pic_serialize(packet_pic_t *, list_t *);
	void send_pic(player_t *, size_t, int *);

	// PIE COMMAND
	packet_pie_t *pie_deserialize(char **);
	bool pie_handler(player_t *, packet_pie_t *);
	void pie_serialize(packet_pie_t *, list_t *);
	void send_pie(player_t *);

	// PFK COMMAND
	packet_pfk_t *pfk_deserialize(char **);
	bool pfk_handler(player_t *, packet_pfk_t *);
	void pfk_serialize(packet_pfk_t *, list_t *);
	void send_pfk(player_t *);

	// PDR COMMAND
	packet_pdr_t *pdr_deserialize(char **);
	bool pdr_handler(player_t *player, packet_pdr_t *);
	void pdr_serialize(packet_pdr_t *, list_t *);
	void send_pdr(player_t *, size_t);

	// PGT COMMAND
	packet_pgt_t *pgt_deserialize(char **);
	bool pgt_handler(player_t *, packet_pgt_t *);
	void pgt_serialize(packet_pgt_t *, list_t *);
	void send_pgt(player_t *, size_t);

	// PDI COMMAND
	packet_pdi_t *pdi_deserialize(char **);
	bool pdi_handler(player_t *player, packet_pdi_t *);
	void pdi_serialize(packet_pdi_t *, list_t *);

	// ENW COMMAND
	packet_enw_t *enw_deserialize(char **);
	bool enw_handler(player_t *player, packet_enw_t *);
	void enw_serialize(packet_enw_t *, list_t *);
	void send_enw(player_t *, size_t);

	// EHT COMMAND
	packet_eht_t *eht_deserialize(char **);
	bool eht_handler(player_t *, packet_eht_t *);
	void eht_serialize(packet_eht_t *, list_t *);
	void send_eht(player_t *, egg_t *);

	// EBO COMMAND
	packet_ebo_t *ebo_deserialize(char **);
	bool ebo_handler(player_t *, packet_ebo_t *);
	void ebo_serialize(packet_ebo_t *, list_t *);
	void send_ebo(player_t *, egg_t *);

	// EDI COMMAND
	packet_edi_t *edi_deserialize(char **);
	bool edi_handler(player_t *, packet_edi_t *);
	void edi_serialize(packet_edi_t *, list_t *);

	// SGT COMMAND
	bool sgt_handler(player_t *, packet_sgt_t *);
	void sgt_serialize(packet_sgt_t *, list_t *);
	packet_sgt_t *sgt_deserialize(char **);

	// TEAM COMMAND
	bool team_handler(player_t *, packet_team_t *);
	void team_serialize(packet_team_t *, list_t *);
	packet_team_t *team_deserialize(char **);

	// SST COMMAND
	bool sst_handler(player_t *, packet_sst_t *);
	void sst_serialize(packet_sst_t *, list_t *);
	packet_sst_t *sst_deserialize(char **);

	// SEG COMMAND
	packet_seg_t *seg_deserialize(char **);
	bool seg_handler(player_t *, packet_seg_t *);
	void seg_serialize(packet_seg_t *, list_t *);

	// SMG COMMAND
	packet_smg_t *smg_deserialize(char **);
	bool smg_handler(player_t *, packet_smg_t *);
	void smg_serialize(packet_smg_t *, list_t *);

	// SUC COMMAND
	packet_suc_t *suc_deserialize(char **);
	bool suc_handler(player_t *, packet_suc_t *);
	void suc_serialize(packet_suc_t *, list_t *);

	// SBP COMMAND
	packet_sbp_t *sbp_deserialize(char **);
	bool sbp_handler(player_t *, packet_sbp_t *);
	void sbp_serialize(packet_sbp_t *, list_t *);

	// UNWRAPPED PACKETS
	void on_unwrapped(player_t *, char **unwrapped);

#endif //ZAPPY_PROTOCOL_H
