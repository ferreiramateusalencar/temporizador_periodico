#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "include/matriz_led.h"
#include "include/led_rgb.h"
#include "include/sprites.h"

typedef enum {
    RED,
    YELLOW,
    GREEN
} traffic_light_state_t;

traffic_light_state_t current_state = RED;

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (current_state) {
        case RED:
            gpio_put(LED_R, 1);
            gpio_put(LED_G, 0);
            gpio_put(LED_B, 0);
            current_state = YELLOW;
            break;
        case YELLOW:
            gpio_put(LED_R, 1);
            gpio_put(LED_G, 1);
            gpio_put(LED_B, 0);
            current_state = GREEN;
            break;
        case GREEN:
            gpio_put(LED_R, 0);
            gpio_put(LED_G, 1);
            gpio_put(LED_B, 0);
            current_state = RED;
            break;
    }
    update_display = true;
    return true;
}

int main() {
    stdio_init_all();
    init_rgb();
    np_init(LED_PIN);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    absolute_time_t next_print = get_absolute_time();

    while (true) {
        if (absolute_time_diff_us(next_print, get_absolute_time()) >= 1000000) {
            next_print = make_timeout_time_ms(1000);
        }

        if (update_display) {
            np_clear();
            for (int i = 0; i < LED_COUNT; i++) {
                if (current_state == RED && sprites[0][i]) {
                    printf("Semaforo Fechado...\n");
                    np_set_led(i, 0, 20, 0);
                } else if (current_state == GREEN && sprites[1][i]) {
                    printf("Atenção, semáforo aberto...\n");
                    np_set_led(i, 20, 20, 0);
                } else if (current_state == YELLOW && sprites[2][i]) {
                    printf("Atenção, semáforo irá fechar...\n");
                    np_set_led(i, 20, 0, 0);
                } 
            }
            np_write();
            update_display = false;
        }
    }
}