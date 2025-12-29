#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  vector<bool> R(H), C(W);
  for (int i = 0; i < H; i++) {
    bool ok = true;
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        ok = false;
      }
    }
    R[i] = ok;
  }
  for (int i = 0; i < W; i++) {
    bool ok = true;
    for (int j = 0; j < H; j++) {
      if (S[j][i] == '#') {
        ok = false;
      }
    }
    C[i] = ok;
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (R[i] || C[j]) {
        continue;
      } else {
        cout << S[i][j];
      }
    }
    if (!R[i]) {
      cout << endl;
    }
  }
}