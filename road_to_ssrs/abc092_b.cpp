#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int D, X;
  cin >> D >> X;
  int ans = X;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    int cur = 1;
    int cnt = 1;
    while (cur + A <= D) {
      cur += A;
      cnt += 1;
    }
    ans += cnt;
  }
  cout << ans << endl;
}