#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      ans += D[i] * D[j];
    }
  }
  cout << ans << endl;
}