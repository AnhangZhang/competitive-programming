#include <bits/stdc++.h>
using namespace std;
int main() {
  int P, Q, R;
  cin >> P >> Q >> R;
  int sum = P + Q + R;
  int ma = max({P, Q, R});
  cout << sum - ma << endl;
}