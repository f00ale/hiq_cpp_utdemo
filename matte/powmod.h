#ifndef POWMOD_H
#define POWMOD_H

#include "log2.h"

uint64_t pow2modn(uint64_t x, uint64_t n) {
  if(x < (1llu << 32))
    return (x*x)%n;

  uint64_t a = x >> 32;
  uint64_t b = x & 0xffffffff;

  uint64_t a2 = a*a;
  uint64_t ab = a*b;
  uint64_t b2 = b*b;

  b2 %= n;

  ab %= n;

  int i = 33;
  while(i > 0) {
    int tmp = 63-log2(ab);
    ab <<= std::min(tmp, i);
    ab %= n;
    i -= tmp;
  }

  a2 %= n;
  i = 64;
  while(i > 0) {
    int tmp = 63-log2(a2);
    a2 <<= std::min(tmp, i);
    a2 %= n;
    i -= tmp;
  }
  /*
  for(int i = 0; i < 64; i+=4) {
    a2 <<= 4;
    if(a2 >= n) a2 %= n;
  }
  */
  return (a2 + ab + b2) % n;

}

uint64_t powmodn(uint64_t a, uint64_t d, uint64_t n) {
  if(d == 0) return 1;
  if(d == 1) return a;
  uint64_t tmp = powmodn(a, d>>1llu, n) % n;
  //  uint64_t ret = (tmp * tmp);
  //  ret %= n;
  uint64_t ret = pow2modn(tmp, n);

  if( d & 1llu ) {
    ret *= a;
    ret %= n;
  }
  //std::cout << "powmod " << a << "^" << d << " (mod " << n << ") = " << ret << std::endl;
  return ret;
}
#endif
