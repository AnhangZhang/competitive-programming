#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  int X, Y;
  cin >> X >> Y;
  cout << (long long)X * min(N, K) + (long long)Y * max(0, N - K) << endl;
}