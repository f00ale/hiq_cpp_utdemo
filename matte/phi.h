// -*- c++ -*-
#ifndef PHI_H
#define PHI_H

#include <stdint.h>
#include "gcd.h"

static uint64_t isqrt(uint64_t n) {
  uint64_t op = n;
  uint64_t res = 0;
  uint64_t one = 1llu << (8*sizeof(uint64_t) - 2);
  while(one > op) one >>= 2;

  while(one != 0) {
    if( op >= res + one) {
      op  -= (res+one);
      res += (one+one);
    }
    res >>= 1;
    one >>= 2;
  }
  return res;
}

uint64_t phi(uint64_t n) {
  if(!n) return 0;

  uint64_t pf = 1;
  uint64_t res = 1;
  uint64_t sqrtn = isqrt(n);

  for(uint64_t p = 2;;) {
    uint64_t ph = p-1llu;
    bool pflag = false;

    while( n % p == 0) {
      if(!pflag && ! (gcd(pf, p) == 1)) break;
      res *= ph;
      ph = p;
      n /= p;
      if(!pflag) pf *= p;
      pflag = true;
    }
    if(pflag) sqrtn = isqrt(n);
    p = (p > 2) ? p+2 : 3;
    if(p > sqrtn) break;
  }

  if(n > 1) res *= (n-1);
  return res;
}

#endif //PHI_H
