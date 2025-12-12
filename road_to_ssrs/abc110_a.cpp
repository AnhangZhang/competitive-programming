#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int mx = max({A, B, C});
  int sum = A + B + C;
  cout << mx * 10 + sum - mx << endl;
}