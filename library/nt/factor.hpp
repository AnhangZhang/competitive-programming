#pragma once

#include "nt/sieve.hpp"

vc<pair<ll, int>> factor_by_lpf(ll n) {
  assert(n < len(lpf));

  vc<pair<ll, int>> res;
  while (n > 1) {
    int p = lpf[n];
    int e = 0;
    while (n % p == 0) {
      n /= p;
      ++e;
    }
    res.eb(p, e);
  }
  return res;
}