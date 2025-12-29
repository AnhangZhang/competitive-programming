#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A.push_back(x);
    while (A.size() >= 4) {
      bool ok = true;
      for (int j = 0; j < 3; j++) {
        ok = ok && A[A.size() - j - 1] == A[A.size() - j - 2];
      }
      if (ok) {
        for (int j = 0; j < 4; j++) {
          A.pop_back();
        }
      } else {
        break;
      }
    }
  }
  cout << A.size() << endl;
}