#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> M(N);
  for (int i = 0; i < N; i++) {
    cin >> M[i];
    X -= M[i];
  }
  sort(M.begin(), M.end());
  int ans = N;
  ans += X / M[0];
  cout << ans << endl;
}