#include <stddef.h>
#include <stdint.h>

#include "rng.h"

#define PRNG_DEFAULT_SEED 0xA5A5A5A5

void prng_init(prng_t *rng, uint32_t seed) {
  if (rng == NULL) {
    return;
  }

  rng->state = seed ? seed : PRNG_DEFAULT_SEED;
}

static uint32_t prng_next(prng_t *rng) {
  if (rng == NULL) {
    return 0U;
  }
  uint32_t x = rng->state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  rng->state = x;
  return x;
}

// TODO: update to input a max range for modularity
uint8_t random_angle(prng_t *rng) {
  if (rng == NULL) {
    return 0U;
  }
  return (uint8_t)prng_next(rng) % 181U;
}
