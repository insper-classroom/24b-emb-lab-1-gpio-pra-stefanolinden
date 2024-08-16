/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
const int BTN = 13;
const int LED = 18;
const int LED2 = 2;
const int LED3 = 3;
const int LED4 = 4;
const int LED5 = 5;


int main() {
    stdio_init_all();
  gpio_init(LED);
  gpio_set_dir(LED, GPIO_OUT);

  gpio_init(LED2);
  gpio_set_dir(LED2, GPIO_OUT);

  gpio_init(LED3);
  gpio_set_dir(LED3, GPIO_OUT);

  gpio_init(LED4);
  gpio_set_dir(LED4, GPIO_OUT);

  gpio_init(LED5);
  gpio_set_dir(LED5, GPIO_OUT);


  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);

    while (true) {
if (!gpio_get(BTN)) {
  for(int i = 0; i < 515; i++){

        gpio_put(LED2,1);
        sleep_ms(5);


        gpio_put(LED2,0);
        gpio_put(LED3,1);
        sleep_ms(5);

        gpio_put(LED3,0);
        gpio_put(LED4,1);
        sleep_ms(5);

        gpio_put(LED4,0);
        gpio_put(LED5,1);
        sleep_ms(5);

        gpio_put(LED5,0);
        sleep_ms(5);

        int X = gpio_get(LED);
        gpio_put(LED,!X);
  }
      

    gpio_put(LED,0);
    }

    }
}
