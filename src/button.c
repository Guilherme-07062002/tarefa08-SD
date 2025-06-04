#include "button.h"
#include "hardware/gpio.h" // Necessário para definições de GPIO
#include "pico/stdlib.h"   // Para sleep_ms

#define DEBOUNCE_MS 200

static uint32_t last_press_time = 0;

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
 * @brief Verifica o estado do Botão B com debounce.
 * @return true se o botão estiver pressionado (com debounce), false caso contrário.
 */
bool button_b_is_pressed() {
    static bool last_state = false;
    bool pressed = gpio_get(BUTTON_B) == 0;
    uint32_t now = to_ms_since_boot(get_absolute_time());

    if (pressed && !last_state && (now - last_press_time > DEBOUNCE_MS)) {
        last_press_time = now;
        last_state = true;
        return true;
    }
    if (!pressed) {
        last_state = false;
    }
    return false;
}
