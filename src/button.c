#include "button.h"
#include "hardware/gpio.h" // Necessário para definições de GPIO

/**
 * @brief Inicializa o botão B.
 * Configura o pino GPIO do botão B como entrada com pull-up interno.
 */
void button_init() {
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

/**
 * @brief Verifica o estado do Botão B.
 * @return true se o botão estiver pressionado, false caso contrário.
 */
bool button_b_is_pressed() {
    return gpio_get(BUTTON_B) == 0;
}
