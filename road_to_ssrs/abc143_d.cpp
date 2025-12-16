#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int p1 = upper_bound(L.begin(), L.end(), L[i] - L[j]) - L.begin();
      int p2 = upper_bound(L.begin(), L.end(), L[j] - L[i]) - L.begin();
      int p = max({p1, p2, j + 1});
      int q = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
      q--;
      ans += max(0, q - p + 1);
    }
  }
  cout << ans << endl;
}