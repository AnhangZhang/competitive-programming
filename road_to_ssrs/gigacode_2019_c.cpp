#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main() {
  int D;
  cin >> D;
  vector<int> A(D);
  for (int i = 0; i < D; i++) {
    cin >> A[i];
  }
  vector<int> B(D);
  for (int i = 0; i < D; i++) {
    cin >> B[i];
  }
  long long cur = 0;
  long long ans = INF;
  for (int i = 0; i < D; i++) {
    if (cur >= B[i]) {
      ans = min(ans, (long long)B[i]);
    }
    cur += A[i];
    if (cur >= B[i]) {
      ans = min(ans, (long long)B[i]);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
}