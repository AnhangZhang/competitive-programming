#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main() {
  int N, K;
  cin >> N >> K;
  long long ans = INF;
  for (int i = 0; i < 1 << N; i++) {
    long long cur = 1;
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        cur *= 2;
      } else {
        cur += K;
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
}