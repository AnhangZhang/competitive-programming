#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  cout << string(M + 2, '#') << endl;
  for (int i = 0; i < N; i++) {
    cout << "#";
    string S;
    cin >> S;
    cout << S << "#" << endl;
  }
  cout << string(M + 2, '#') << endl;
}