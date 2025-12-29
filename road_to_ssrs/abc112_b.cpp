#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  int N, T;
  cin >> N >> T;
  int ans = INF;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;
    if (t <= T) {
      ans = min(ans, c);
    }
  }
  if (ans == INF) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }
}