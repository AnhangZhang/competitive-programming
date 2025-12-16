#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<string> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for (int i = 0; i + M - 1 < N; i++) {
    for (int j = 0; j + M - 1 < N; j++) {
      bool ok = true;
      for (int x = 0; x < M; x++) {
        for (int y = 0; y < M; y++) {
          if (A[i + x][j + y] != B[x][y]) {
            ok = false;
          }
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}