#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<pair<int, int>>> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i].resize(A[i]);
    for (int j = 0; j < A[i]; j++) {
      cin >> B[i][j].first >> B[i][j].second;
      B[i][j].first--;
    }
  }
  int ans = 0;
  for (int i = 0; i < 1 << N; i++) {
  }
  cout << ans << endl;
}