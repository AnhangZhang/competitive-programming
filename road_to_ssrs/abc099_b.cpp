#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> A;
  int cur = 0;
  for (int i = 1; i < 1000; i++) {
    cur += i;
    A.push_back(cur);
  }
  int a, b;
  cin >> a >> b;
  for (int i = 0; i + 1 < A.size(); i++) {
    int ga = A[i] - a;
    int gb = A[i + 1] - b;
    if (ga > 0 && gb > 0 && ga == gb) {
      cout << ga << endl;
      return 0;
    }
  }
}