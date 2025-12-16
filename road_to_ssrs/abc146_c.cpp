#include <bits/stdc++.h>
using namespace std;
long long TEN(int len) {
  if (len == 0) {
    return 1;
  } else {
    return TEN(len - 1) * 10;
  }
}
int get_len(long long x) { return to_string(x).size(); }
int main() {
  long long A, B, X;
  cin >> A >> B >> X;
  long long ans = 0;
  for (int len = 10; len >= 1; len--) {
    long long X2 = X - B * len;
    if (X2 > 0) {
      int l = get_len(X2 / A);
      if (l == len) {
        ans = max(ans, X2 / A);
      }
      if (l > len) {
        ans = max(ans, TEN(len) - 1);
      }
    }
  }
  ans = min(ans, (long long)1000000000);
  cout << ans << endl;
}