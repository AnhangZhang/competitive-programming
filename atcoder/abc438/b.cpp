#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  int ans = INF;
  for (int i = 0; i + M - 1 < N; i++) {
    int cnt = 0;
    for (int j = 0; j < M; j++) {
      cnt += (S[i + j] - T[j] + 10) % 10;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}