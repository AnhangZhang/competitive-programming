#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  cin >> N;
  for (long long i = sqrt(N) + 1; i >= 1; i--) {
    if (N % i == 0) {
      cout << i - 1 + N / i - 1 << endl;
      return 0;
    }
  }
}