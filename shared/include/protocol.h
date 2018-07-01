/*
** EPITECH PROJECT, 2018
** ZAAPPY
** File description:
** PROTOCOLE
*/

#ifndef ZAPPY_PROTOCOL_H
	#define ZAPPY_PROTOCOL_H

	#include <stdint.h>
	#include <sys/types.h>
	#include "zappy_network.h"
	#include "network.h"

	#define ZAPPY_BUFFER_SIZE (2048)
	#define ZAPPY_PACKET_DELIMITER ("\n")
	#define ZAPPY_PARAM_SEPARATOR (" ")

	typedef struct command_s message_t;

	typedef void (*handler_t)(session_t client, void *msg);
	typedef void (*serialize_t)(void *msg, list_t *buffer);
	typedef void *(*deserialize_t)(char **args);

	struct command_s {
		char const *named;
		serialize_t serialize;
		deserialize_t deserialize;
		handler_t *handler;
	};

	//PACKET MSZ
	packet_msz_t *deserialize_msz(char **args);
	void serialize_msz(packet_msz_t *msg, list_t *buffer);

	//PACKET BCT
	packet_bct_tile_t *deserialize_bct(char **args);
	void serialize_bct(packet_bct_tile_t *msg, list_t *buffer);

	//PACKET TNA
	packet_tna_t *deserialize_tna(char **args);
	void serialize_tna(packet_tna_t *packet, list_t *buffer);

	//PACKET PNW
	packet_pnw_t *deserialize_pnw(char **args);

	//PACKET PPO
	packet_ppo_t *deserialize_ppo(char **args);
	void serialize_ppo(packet_ppo_t *msg, list_t *buffer);

	//PACKET PLV
	packet_plv_t *deserialize_plv(char **args);
	void serialize_plv(packet_plv_t *msg, list_t *buffer);

	//PACKET PIN
	packet_pin_t *deserialize_pin(char **args);
	void serialize_pin(packet_pin_t *msg, list_t *buffer);

	//PACKET PEX
	packet_pex_t *deserialize_pex(char **args);

	//PACKET PBC
	packet_pbc_t *deserialize_pbc(char **args);

	//PACKET PIE
	packet_pie_t *deserialize_pie(char **args);

	//PACKET PFK
	packet_pfk_t *deserialize_pfk(char **args);

	//PACKET PDR
	packet_pdr_t *deserialize_pdr(char **args);

	//PACKET PGT
	packet_pgt_t *deserialize_pgt(char **args);

	//PACKET PDI
	packet_pdi_t *deserialize_pdi(char **args);

	//PACKET ENW
	packet_enw_t *deserialize_enw(char **args);

	//PACKET EHT
	packet_eht_t *deserialize_eht(char **args);

	//PACKET EBO
	packet_ebo_t *deserialize_ebo(char **args);

	//PACKET EDI
	packet_edi_t *deserialize_edi(char **args);

	//PACKET SGT
	packet_sgt_t *deserialize_sgt(char **args);
	void serialize_sgt(packet_sgt_t *packet, list_t *buffer);

	//PACKET SST
	packet_sst_t *deserialize_sst(char **args);
	void serialize_sst(packet_sst_t *msg, list_t *buffer);

	//PACKET SEG
	packet_seg_t *deserialize_seg(char **args);

	//PACKET SMG
	packet_smg_t *deserialize_smg(char **args);

	//PACKET SUC
	packet_suc_t *deserialize_suc(char **args);

	//PACKET SBP
	packet_sbp_t *deserialize_sbp(char **args);

	//PACKET PIC
	packet_pic_t *deserialize_pic(char **args);

	//PACKET WELCOME
	packet_welcome_t *deserialize_welcome(char **args);

	//PACKET MESSAGE
	packet_message_t *deserialize_message(char **args);

	//PACKET LOOK
	packet_look_t *deserialize_look(char **args);
	void serialize_look(packet_look_t *packet, list_t *buffer);

	//PACKET INVENTORY
	packet_inventory_t *deserialize_inventory(char **args);
	void serialize_inventory(packet_inventory_t *packet, list_t *buffer);

	//PACKET CONNECT NUMBER
	packet_connect_number_t *deserialize_connect_number(char **args);
	void serialize_connect_number(packet_connect_number_t *packet, list_t *buffer);

	//PACKET BROADCAST
	void serialize_broadcast(packet_broadcast_t *packet, list_t *buffer);

#endif
