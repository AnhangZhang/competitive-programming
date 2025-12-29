#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<bool> used(N);
  int cur = 0;
  int cnt = 0;
  while (!used[cur]) {
    if (cur == 1) {
      cout << cnt << endl;
      return 0;
    }
    used[cur] = true;
    cur = A[cur];
    cnt++;
  }
  cout << -1 << endl;
}