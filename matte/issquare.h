#include "phi.h"

bool issquare(uint64_t n) {
  //  uint64_t tmp = isqrt(n);
  //  return tmp*tmp == n;
  switch(n%10) {
    case 0: if(n%100 == 0) return issquare(n/100);
            else return false;
    case 1:
    case 4:
    case 5:
    case 6:
    case 9:
        {
          uint64_t tmp = isqrt(n);
          return tmp*tmp == n;
        }
  }
  return false;
}
