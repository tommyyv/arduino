#include <stdint.h>

// D13 - PB5: built-in led

typedef struct {
  volatile uint8_t PIN;  // input
  volatile uint8_t DDR;  // data direction
  volatile uint8_t PORT; // output
} GPIO_Port;

#define GPIOB                                                                  \
  ((GPIO_Port *)0x23) // this just becomes (*(volatile uint8_t*)0x23), which can
                      // be ptr + 1 = next address

void gpio_set(GPIO_Port *gpio, uint8_t bit) {
  gpio->PORT |= (1 << bit);
} // port, pin; |= ()

void gpio_clear(GPIO_Port *gpio, uint8_t bit) {
  gpio->PORT &= ~(1 << bit);
} // port, pin; &= ~

void gpio_toggle(GPIO_Port *gpio, uint8_t bit) {
  gpio->PORT ^= (1 << bit);
} // port, pin; ^=

int main(void) {
  GPIOB->DDR |= (1 << 5);
  while (1) {
    gpio_toggle(GPIOB, 5);
    for (volatile uint32_t i = 0; i < 10000; i++)
      ;
  }
}
