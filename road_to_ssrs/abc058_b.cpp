#include <bits/stdc++.h>
using namespace std;
int main() {
  string O, E;
  cin >> O >> E;
  for (int i = 0, j = 0; i < O.size() || j < E.size(); i++, j++) {
    if (i < O.size()) {
      cout << O[i];
    }
    if (j < E.size()) {
      cout << E[j];
    }
  }
  cout << endl;
}