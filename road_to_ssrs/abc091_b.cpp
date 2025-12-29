#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int M;
  cin >> M;
  vector<string> T(M);
  for (int i = 0; i < M; i++) {
    cin >> T[i];
  }
  set<string> st(S.begin(), S.end());
  int ans = 0;
  for (auto s : st) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] == s) {
        cnt++;
      }
    }
    for (int i = 0; i < M; i++) {
      if (T[i] == s) {
        cnt--;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}