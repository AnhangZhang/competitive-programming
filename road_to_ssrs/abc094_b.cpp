#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<bool> B(N + 1);
  for (int i = 0; i < M; i++) {
    int A;
    cin >> A;
    B[A] = true;
  }
  int ans = N + 1;
  int cur = 0;
  for (int i = X; i <= N; i++) {
    if (B[i]) {
      cur++;
    }
  }
  ans = min(ans, cur);
  cur = 0;
  for (int i = X; i >= 0; i--) {
    if (B[i]) {
      cur++;
    }
  }
  ans = min(ans, cur);
  cout << ans << endl;
}