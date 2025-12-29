#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int main() {
  int N;
  cin >> N;
  for (int X = 1; X <= MAX; X++) {
    if (int(X * 1.08) == N) {
      cout << X << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
}