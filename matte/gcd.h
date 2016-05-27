// -*- c++ -*-
#ifndef GCD_H
#define GCD_H

#include <stdint.h>
#include <algorithm>

uint64_t gcd(uint64_t a, uint64_t b) {
  if(a == 0 || b == 0) return (a | b);

  int s;

  for(s = 0; ((a | b) & 1) == 0; ++s) {
    a >>= 1;
    b >>= 1;
  } 

  while( ! (a & 1) ) a >>= 1;

  do {
    while( ! (b & 1)) b >>= 1;

    if(a < b) b -= a;
    else {
      a -= b;
      std::swap(a, b);
    }

    b >>= 1;

  } while( b );

  return a << s;
}

#endif //GCD_H
