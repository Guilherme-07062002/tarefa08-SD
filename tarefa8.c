#include <stdio.h>
#include "pico/stdlib.h"
#include "globals.h"
#include "display.h"
#include "button.h"
#include "logic.h"
#include "expansion_board.h"

/**
 * @brief Inicializa periféricos: UART, I2C, display OLED e botões.
 */
void inicializa() {
    stdio_init_all();
    button_init();
    init_display();
    expansion_board_init();
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
    static bool exibiu = false;
    if (button_b_is_pressed()) {
        if (!exibiu) {
            // Use a leitura real da DIP switch
            uint8_t valorDIP = expansion_board_read_dip();
            int bits[8];
            for (int i = 0; i < 8; i++) {
                bits[i] = (valorDIP >> (7 - i)) & 1;
            }
            int valorDecimal = BinaryToDecimal(bits);
            printf("Valor lido da DIP switch: 0x%02X\n", valorDIP);
            printf("Valor Decimal: %d\n", valorDecimal);

            char msg[20];
            snprintf(msg, sizeof(msg), "%d", valorDecimal);
            clear_display(); // Limpa o display antes de exibir o novo valor
            print_texto(msg, 18, 3);

            exibiu = true;
        }
    } else {
        exibiu = false;
    }
}

/**
 * @brief Função principal.
 */
int main() {
    inicializa();
    while (1) {
        comportamento_principal();
        sleep_ms(10); // Use um valor maior para evitar uso excessivo de CPU
    }
    return 0;
}
