#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> A(3);
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  int S;
  cin >> S;
  for (int i = 0; i < 8; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += A[j] + (i >> j & 1);
    }
    if (sum == S) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}