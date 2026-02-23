#pragma once

vc<int> lpf, primes;
void sieve(int LIM) {
  chmax(LIM, 1);
  lpf.assign(LIM + 1, 0);
  primes.clear();

  FOR(i, 2, LIM + 1) {
    if (lpf[i] == 0) {
      lpf[i] = i;
      primes.eb(i);
    }

    for (auto p : primes) {
      if (i * p > LIM) break;

      lpf[i * p] = p;
      if (p == lpf[i]) break;
    }
  }
}