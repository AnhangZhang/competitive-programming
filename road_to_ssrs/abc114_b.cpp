#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int ans = INF;
  for (int i = 0; i + 2 < N; i++) {
    int v = stoi(S.substr(i, 3));
    ans = min(ans, abs(v - 753));
  }
  cout << ans << endl;
}