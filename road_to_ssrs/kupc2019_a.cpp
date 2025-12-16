#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] + X >= A[N - 1]) {
      ans++;
    }
  }
  cout << ans << endl;
}