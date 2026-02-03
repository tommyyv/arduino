#include "rng.h"
#include <stdint.h>

typedef struct {
  volatile uint8_t PIN;  // input
  volatile uint8_t DDR;  // data direction
  volatile uint8_t PORT; // output
} gpio_port_t;

typedef struct {
  uint16_t min_us;
  uint16_t max_us;
  uint16_t period_us;
} servo_config_t;

#define GPIOD ((gpio_port_t *)0x2B)

// what register to control the servo? pin? port? ddr?
// ddrd3: 0x2a
// portd3: 0x2b
// bit 3

void gpio_set(gpio_port_t *gpio, uint8_t bit) {
  gpio->PORT |= (1 << bit);
} // port, pin; |= ()

void gpio_clear(gpio_port_t *gpio, uint8_t bit) {
  gpio->PORT &= ~(1 << bit);
} // port, pin; &= ~

void gpio_toggle(gpio_port_t *gpio, uint8_t bit) {
  gpio->PORT ^= (1 << bit);
} // port, pin; ^=

void delay() {
  for (volatile uint32_t i = 0; i < 100000; i++)
    ;
}
// how to generate random numbers up to 180
// how can i randomly select an index from the array?

int main(void) {
  int rand_angle = 180;
  GPIOD->DDR |= (1 << 3);
  delay();

  if (rand_angle > 180)
    rand_angle = 180;
}
