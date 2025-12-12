#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vd = vector<db>;
using vl = vector<ll>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vpl = vector<pl>;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define FOR(i, a, n) for (int i = (a); i < (n); i++)
#define F0R(i, n) FOR(i, 0, n)
#define FORd(i, a, n) for (int i = (n) - 1; i >= (a); i--)
#define F0Rd(i, n) FORd(i, 0, n)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto a : x)

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

template <class T, class U> bool ckmin(T &a, const U b) { return b < a ? a = b, true : false; }
template <class T, class U> bool ckmax(T &a, const U b) { return b > a ? a = b, true : false; }

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif

const char nl = '\n';

struct UnionFind {
  int cnt = 0;
  vector<int> p;
  UnionFind(int n) {
    p = vector<int>(n, -1);
    cnt = n;
  }
  int root(int x) {
    if (p[x] < 0) {
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
      cnt--;
      return true;
    } else {
      return false;
    }
  }
};

void solve([[maybe_unused]] int tc = 1) {
  int N, M; cin >> N >> M;
  vector<pair<int, pi>> edges(M);
  F0R(i, M) {
    int C, L, R; cin >> C >> L >> R; L--;
    edges.pb(mp(C, mp(L, R)));
  }
  sort(all(edges));

  UnionFind UF(N+1);
  ll ans = 0;
  each(e, edges) {
    if (UF.unite(e.s.f, e.s.s)) {
      ans += e.f;
    }
  }
  if (UF.cnt == 1) {
    cout << ans << nl;
  } else {
    cout << -1 << nl;
  }
}

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  cout << setprecision(20);

  int T = 1;
  // cin >> T; 
  for (int i = 0; i < T; i++) {
    solve(i + 1);
  }
}