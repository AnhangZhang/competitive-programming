#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int x = i;
    int res = 0;
    while (x > 0) {
      res += x % 10;
      x /= 10;
    }
    if (A <= res && res <= B) {
      ans += i;
    }
  }
  cout << ans << endl;
}