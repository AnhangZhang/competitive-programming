#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int main() {
  int N;
  cin >> N;
  vector<int> imos(MAX);
  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    imos[l]++;
    if (r < MAX) {
      imos[r]--;
    }
  }
  for (int i = 1; i < MAX; i++) {
    imos[i] += imos[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < MAX; i++) {
    ans += imos[i];
  }
  cout << ans << endl;
}