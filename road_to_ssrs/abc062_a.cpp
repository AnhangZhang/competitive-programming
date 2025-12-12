#include <bits/stdc++.h>
using namespace std;
const vector<vector<int>> T = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 0; i < 3; i++) {
    bool f = false, g = false;
    for (int j = 0; j < T[i].size(); j++) {
      if (x == T[i][j]) {
        f = true;
      }
      if (y == T[i][j]) {
        g = true;
      }
    }
    if (f && g) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}