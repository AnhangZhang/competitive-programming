#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  vector<vector<int>> S(H, vector<int>(W));
  if (A == 0 && B != 0) {
    for (int i = 0; i < B; i++) {
      for (int j = 0; j < W; j++) {
        S[i][j] = 1;
      }
    }
  } else if (A != 0 && B == 0) {
    for (int j = 0; j < A; j++) {
      for (int i = 0; i < H; i++) {
        S[i][j] = 1;
      }
    }
  } else if (A != 0 && B != 0) {
    if (H % B != 0 || W % A != 0 || H / B != W / A) {
      cout << -1 << endl;
      return 0;
    }
    int j = 0, k = 0;
    for (int i = 0; i < H / B; i++) {
      for (int j2 = 0; j2 < B; j2++) {
        for (int k2 = 0; k2 < A; k2++) {
          S[j + j2][k + k2] = 1;
        }
      }
      j += B;
      k += A;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << S[i][j];
    }
    cout << endl;
  }
}