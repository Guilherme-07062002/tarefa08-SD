#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "display.h"
#include "button.h"
#include "logic.h" // Para funções de lógica

/**
 * @brief Inicializa periféricos: UART, I2C, display OLED e botões.
 */
void inicializa() {
    stdio_init_all();
    button_init();
    init_display();
}

/**
 * @brief Simula a leitura de uma DIP switch.
 * @return Valor simulado representando o estado dos switches.
 */
uint8_t simular_leitura_DIP() {
    return 0b10101010; // Valor simulado da DIP switch
}

/**
 * @brief Converte um vetor binário de 8 bits para decimal.
 * @param a Vetor de inteiros (0 ou 1) de tamanho 8.
 * @return Valor decimal correspondente.
 */
int BinaryToDecimal(int a[]) {
    int sum = 0;
    int mul = 128;
    for (int i = 0; i < 8; i++) {
        if (a[i] == 1) {
            sum += mul;
        }
        mul /= 2;
    }
    return sum;
}

/**
 * @brief Comportamento principal do programa.
 * Lê o valor da DIP switch ao pressionar o botão B e exibe no display e console.
 */
void comportamento_principal() {
    if (button_b_is_pressed()) {
        uint8_t valorDIP = simular_leitura_DIP();
        int bits[8];
        for (int i = 0; i < 8; i++) {
            bits[i] = (valorDIP >> (7 - i)) & 1;
        }
        int valorDecimal = BinaryToDecimal(bits);
        printf("Valor lido da DIP switch: 0x%02X\n", valorDIP);
        printf("Valor Decimal: %d\n", valorDecimal);
        
        char msg[20];
        snprintf(msg, sizeof(msg), "%d", valorDecimal); // Corrigido para exibir decimal
        print_texto(msg, 18, 3);
    }
}

/**
 * @brief Função principal.
 */
int main() {
    inicializa();
    while (1) {
        comportamento_principal();
        sleep_ms(100);
    }
    return 0;
}
