#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main() {
  int N;
  cin >> N;
  int T, A;
  cin >> T >> A;
  A *= 1000;
  int gap = INF, ans = -1;
  for (int i = 0; i < N; i++) {
    int h;
    cin >> h;
    int g = abs(T * 1000 - h * 6 - A);
    if (g < gap) {
      gap = g;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
}