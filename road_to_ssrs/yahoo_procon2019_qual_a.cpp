#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  if (N - N / 2 >= K) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}