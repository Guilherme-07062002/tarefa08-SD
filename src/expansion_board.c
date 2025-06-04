#include "expansion_board.h"

#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

void expansion_board_init() {
    gpio_init(LOAD_PIN);
    gpio_init(CLK_PIN);
    gpio_init(DATA_PIN);

    gpio_set_dir(LOAD_PIN, GPIO_OUT);
    gpio_set_dir(CLK_PIN, GPIO_OUT);
    gpio_set_dir(DATA_PIN, GPIO_IN); // Corrigido para entrada
}

uint8_t expansion_board_read_dip() {
    uint8_t value = 0;

    // Carrega o estado dos switches no registrador
    gpio_put(LOAD_PIN, 0);
    sleep_us(1);
    gpio_put(LOAD_PIN, 1);
    sleep_us(1);

    // Lê 8 bits do registrador de deslocamento
    for (int i = 0; i < 8; i++) {
        value <<= 1;
        value |= gpio_get(DATA_PIN);
        gpio_put(CLK_PIN, 1);
        sleep_us(1);
        gpio_put(CLK_PIN, 0);
        sleep_us(1);
    }
    return value;
}