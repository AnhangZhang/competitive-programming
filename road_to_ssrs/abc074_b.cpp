#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += min(X[i] * 2, (K - X[i]) * 2);
  }
  cout << ans << endl;
}