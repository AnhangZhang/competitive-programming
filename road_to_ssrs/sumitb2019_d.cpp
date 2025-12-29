#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<vector<int>> P(10);
  for (int i = 0; i < N; i++) {
    P[S[i] - '0'].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    string T = to_string(i);
    if (T.size() < 3) {
      T = string(3 - T.size(), '0') + T;
    }
    int cur = -1;
    for (int j = 0; j < 4; j++) {
      if (j == 3) {
        ans++;
        break;
      }
      int v = T[j] - '0';
      auto it = upper_bound(P[v].begin(), P[v].end(), cur);
      if (it == P[v].end()) {
        break;
      }
      cur = *it;
    }
  }
  cout << ans << endl;
}