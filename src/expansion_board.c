#include "expansion_board.h"

#include "hardware/gpio.h"
#include "hardware/pwm.h"

void expansion_board_init() {
    gpio_init(LOAD_PIN);
    gpio_init(CLK_PIN);
    gpio_init(DATA_PIN);

    gpio_set_dir(LOAD_PIN, GPIO_OUT);
    gpio_set_dir(CLK_PIN, GPIO_OUT);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
}
