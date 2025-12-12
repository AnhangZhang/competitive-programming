#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> A(5);
  for (int i = 0; i < 5; i++) {
    cin >> A[i];
  }
  int K;
  cin >> K;
  bool ok = true;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (abs(A[i] - A[j]) > K) {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "Yay!" << endl;
  } else {
    cout << ":(" << endl;
  }
}