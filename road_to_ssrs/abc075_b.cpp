#include <bits/stdc++.h>
using namespace std;
const int di[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dj[] = {0, 1, 0, -1, 1, -1, -1, 1};
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  vector<vector<int>> ans(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        for (int k = 0; k < 8; k++) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] != '#') {
            ans[ni][nj]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        cout << '#';
      } else {
        cout << ans[i][j];
      }
    }
    cout << endl;
  }
}