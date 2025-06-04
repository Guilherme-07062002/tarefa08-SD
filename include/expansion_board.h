#ifndef EXPANSION_BOARD_H
#define EXPANSION_BOARD_H
#include "globals.h"

#define LOAD_PIN 28 // Pino de Load
#define CLK_PIN 17  // Pino de Clock
#define DATA_PIN 16 // Pino de Saída Serial

/**
 * @brief Inicializa os pinos para o funcionamento do Expansion Board.
 */
void expansion_board_init();


#endif // EXPANSION_BOARD_H