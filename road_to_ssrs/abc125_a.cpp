#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, T;
  cin >> A >> B >> T;
  int ans = 0;
  int cur = A;
  while (cur <= T) {
    ans += B;
    cur += A;
  }
  cout << ans << endl;
}