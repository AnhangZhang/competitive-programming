#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  vector<string> S2(2 * H, string(W, '?'));
  S2[0] = S[0];
  for (int i = 1; i < 2 * H; i++) {
    for (int j = 0; j < W; j++) {
      S2[i][j] = S[i / 2][j];
    }
  }
  for (int i = 0; i < 2 * H; i++) {
    cout << S2[i] << endl;
  }
}