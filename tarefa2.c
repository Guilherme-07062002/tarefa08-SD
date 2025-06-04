#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "display.h"
#include "button.h"
#include "logic.h" // Incluído para usar as funções de lógica

// Função para inicializar periféricos
void inicializa() {
    stdio_init_all();

    // Inicializa I2C e display OLED
    init_display();

    // Inicializa botões
    button_init();
}

/**
 * Comportamento principal do programa.
 */
void comportamento_principal() {
    execute_logic_operation(); // Executa a operação lógica correspondente
}

// Função principal
int main() {
    inicializa();

    while (1) {
        comportamento_principal();
        sleep_ms(100);
    }

    return 0;
}
