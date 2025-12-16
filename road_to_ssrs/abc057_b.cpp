#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  vector<int> C(M), D(M);
  for (int i = 0; i < M; i++) {
    cin >> C[i] >> D[i];
  }
  for (int i = 0; i < N; i++) {
    int dist = INF, id = -1;
    for (int j = 0; j < M; j++) {
      int d = abs(A[i] - C[j]) + abs(B[i] - D[j]);
      if (d < dist) {
        dist = d;
        id = j;
      }
    }
    cout << id + 1 << endl;
  }
}