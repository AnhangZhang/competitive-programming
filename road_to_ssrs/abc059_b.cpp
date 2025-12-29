#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() < B.size()) {
    cout << "LESS" << endl;
  } else if (A.size() > B.size()) {
    cout << "GREATER" << endl;
  } else {
    int N = A.size();
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (A[i] < B[i]) {
        cout << "LESS" << endl;
        ok = false;
        break;
      } else if (A[i] > B[i]) {
        cout << "GREATER" << endl;
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "EQUAL" << endl;
    }
  }
}