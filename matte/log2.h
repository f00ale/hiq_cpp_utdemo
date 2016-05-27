#ifndef LOG2_H
#define LOG2_H

#include <stdint.h>

static uint32_t log2(uint64_t v) {
  const uint64_t b[] = { 0x2, 0xc, 0xf0, 0xff00, 0xffff0000, 0xffffffff00000000llu };
  const uint32_t S[] = { 1, 2, 4, 8, 16, 32 };

  uint32_t ret = 0;
  for(int32_t i = 5; i >= 0; i--) {
    if(v & b[i]) {
      v >>= S[i];
      ret |= S[i];
    }
  }
  return ret;
}

#endif
