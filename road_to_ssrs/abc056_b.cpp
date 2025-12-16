#include <bits/stdc++.h>
using namespace std;
int main() {
  int W, a, b;
  cin >> W >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  cout << max(0, b - a - W) << endl;
}