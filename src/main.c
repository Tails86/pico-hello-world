#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main()
{
    // Turn on LED
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, true);
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    // Initialize stdio through USB
    stdio_usb_init();

    while (true)
    {
        printf("Hello\n");
        gpio_xor_mask(1 << PICO_DEFAULT_LED_PIN);
        sleep_ms(1000);

        printf("World\n");
        gpio_xor_mask(1 << PICO_DEFAULT_LED_PIN);
        sleep_ms(1000);
    }
    return 0;
}