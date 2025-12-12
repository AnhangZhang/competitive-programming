#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0;
  for (int i = 0; i < 3; i++) {
    int a;
    cin >> a;
    x = x * 10 + a;
  }
  if (x % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}