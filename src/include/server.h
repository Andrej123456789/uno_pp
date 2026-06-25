/**
 * @author Andrej123456789 (Andrej Bartulin)
 * PROJECT: uno++
 * LICENSE: MIT license
 * DESCRIPTION: Server code
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>

struct Player;

#define BUFFER_LIMIT 255

/**
 * Start a server
 * @param port port number
 * @param number_of_players total number of players in the game
 * @return int
 */
int net_start_server(uint16_t port, uint16_t number_of_players);

/**
 * Accept a client's connection to the server
 * @param listener_fd file descriptor
 * @param players array of `Player` structs
 * @param number_of_players total number of players in the game
 * @return void
 */
void net_accept_clients(int listener_fd, Player* players, int number_of_players);

/**
 * Poll input from clients
 * @param players array of `Player` structs
 * @param number_of_players total number of players in the game
 * @return void
 */
void net_poll_clients(Player* players, int number_of_players);

/**
 * Send a message to one player
 * @param p player
 * @param fmt message
 * @return void
 */
void send_to_player(Player* p, const char* fmt, ...);

/**
 * Send a message to all players
 * @param players array of `Player` structs
 * @param number_of_players total number of players in the game
 * @param fmt message
 * @param void
 */
void broadcast(Player* players, int number_of_players, const char* fmt, ...);
