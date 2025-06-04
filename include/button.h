#ifndef BUTTON_H
#define BUTTON_H
#include "globals.h"

// Pinos dos botões
#define BUTTON_A 5    // GPIO conectado ao Botão A
#define BUTTON_B 6    // GPIO conectado ao Botão B

/**
 * @brief Inicializa os botões.
 */
void button_init();

/**
 * @brief Verifica se o Botão B está pressionado.
 * @return true se pressionado, false caso contrário.
 */
bool button_b_is_pressed();

#endif // BUTTON_H