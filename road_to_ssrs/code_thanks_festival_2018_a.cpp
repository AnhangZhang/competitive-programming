#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, A, B, C, D;
  cin >> T >> A >> B >> C >> D;
  int ans = 0;
  if (C <= T) {
    ans += D;
    T -= C;
  }
  if (A <= T) {
    ans += B;
    T -= A;
  }
  cout << ans << endl;
}