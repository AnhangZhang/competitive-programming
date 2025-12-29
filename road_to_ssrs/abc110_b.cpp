#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  vector<int> y(M);
  for (int i = 0; i < M; i++) {
    cin >> y[i];
  }
  for (int z = X + 1; z <= Y; z++) {
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (x[i] >= z) {
        ok = false;
      }
    }
    for (int i = 0; i < M; i++) {
      if (y[i] < z) {
        ok = false;
      }
    }
    if (ok) {
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}