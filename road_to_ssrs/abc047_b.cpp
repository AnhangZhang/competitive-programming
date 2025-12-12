#include <bits/stdc++.h>
using namespace std;
int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<vector<int>> A(W, vector<int>(H));
  for (int i = 0; i < N; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      for (int x2 = 0; x2 < x; x2++) {
        for (int y2 = 0; y2 < H; y2++) {
          A[x2][y2] = 1;
        }
      }
    }
    if (a == 2) {
      for (int x2 = x; x2 < W; x2++) {
        for (int y2 = 0; y2 < H; y2++) {
          A[x2][y2] = 1;
        }
      }
    }
    if (a == 3) {
      for (int x2 = 0; x2 < W; x2++) {
        for (int y2 = 0; y2 < y; y2++) {
          A[x2][y2] = 1;
        }
      }
    }
    if (a == 4) {
      for (int x2 = 0; x2 < W; x2++) {
        for (int y2 = y; y2 < H; y2++) {
          A[x2][y2] = 1;
        }
      }
    }
  }
  int ans = W * H;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      ans -= A[i][j];
    }
  }
  cout << ans << endl;
}