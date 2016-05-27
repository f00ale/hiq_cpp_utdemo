#ifndef ISPRIME_H
#define ISPRIME_H

/*
  this file implements a determenistic miller-rabin primality test.
  see:
  http://primes.utm.edu/prove/prove2_3.html
  http://www.ams.org/mcom/2003-72-244/S0025-5718-03-01545-X/home.html
  http://en.wikipedia.org/wiki/Miller-Rabin
 */

#include <stdint.h>
#include <iostream>

#include "powmod.h"

bool testbase(uint64_t a, uint64_t d, uint64_t s, uint64_t n) {
  uint64_t tmp0 = powmodn(a, d, n);
  uint64_t tmp1 = 0;
  uint64_t i;
  for(i = 1; i <= s; i++) {
    tmp1 = powmodn(tmp0, 2, n);
    if(tmp1 == 1 && tmp0 != 1 && tmp0 != (n-1llu)) return false;
    if(i == s && tmp1 != 1) return false;
    tmp0 = tmp1;
  }
  return true;
} 


bool isprime(uint64_t n) {
  if(n<2) return false;
  if(n==2 || n == 3) return true;
  if(! (n&1)) return false;
  uint64_t d = n - 1;
  uint64_t s = 0;
  while(! (d&1)) {
    s++;
    d>>=1;
  }

  //  std::cout << n << "-1 = " << d << "*2^" << s << std::endl;

  if(!testbase(2, d, s, n)) return false;
  if(!testbase(3, d, s, n)) return false;
  if(n < 1373653llu) return true;

  if(!testbase(5, d, s, n)) return false;
  if(n < 25326001llu) return true;

  if(n == 3215031751llu) return false; // this seems to be a false positive
  if(!testbase(7, d, s, n)) return false;
  if(n < 118670087467llu) return true;

  if(!testbase(11, d, s, n)) return false;
  if(n < 2152302898747llu) return true;

  if(!testbase(13, d, s, n)) return false;
  if(n < 3474749660383llu) return true;

  if(!testbase(17, d, s, n)) return false;
  if(n < 341550071728321llu) return true;

  // this is if I interpret http://www.ams.org/mcom/2003-72-244/S0025-5718-03-01545-X/home.html correctly...
  if(!testbase(19, d, s, n)) return false;
  if(!testbase(23, d, s, n)) return false;
  if(!testbase(29, d, s, n)) return false;
  if(!testbase(31, d, s, n)) return false;
  if(n < 3825123056546413051llu) return true;

  std::cout << "can't determine primeness of " << n << std::endl;
  return false;
}

#endif
