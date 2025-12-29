#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int cur = 1;
  while (cur * 2 <= N) {
    cur *= 2;
  }
  cout << cur << endl;
}