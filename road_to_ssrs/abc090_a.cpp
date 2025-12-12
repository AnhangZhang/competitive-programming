#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> C(3);
  for (int i = 0; i < 3; i++) {
    cin >> C[i];
  }
  for (int i = 0; i < 3; i++) {
    cout << C[i][i];
  }
  cout << endl;
}