#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128_t;

// pairs
using pi = pair<ll, ll>;
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second

using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq_max = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define all(x) (x).begin(), (x).end()
#define len(x) ((ll)(x).size())

// loops
// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'100'000'000;
template <>
constexpr ll infty<ll> = 2'200'000'000'000'000'000;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;
template <>
constexpr double infty<double> = numeric_limits<double>::infinity();
template <>
constexpr long double infty<long double> =
    numeric_limits<long double>::infinity();

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <class T>
T kth_bit(int k) {
  return T(1) << k;
}
template <class T>
bool has_bit(T x, int k) {
  return (x >> k & 1);
}

#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
template <class T, class U>
T SUM(const U &x) {
  return accumulate(all(x), T(0));
}
template <class C, class T>
inline long long LB(const C &c, const T &x) {
  return lower_bound(c.begin(), c.end(), x) - c.begin();
}
template <class C, class T>
inline long long UB(const C &c, const T &x) {
  return upper_bound(c.begin(), c.end(), x) - c.begin();
}
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T>
T POP(queue<T> &que) {
  T a = que.front();
  que.pop();
  return a;
}
template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <class T, class Container, class Compare>
T POP(priority_queue<T, Container, Compare> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll find_first_true(F check, ll low, ll high) {
  ++high;
  assert(low <= high);
  while (low < high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
template <typename F>
ll find_last_true(F check, ll low, ll high) {
  --low;
  assert(low <= high);
  while (low < high) {
    ll mid = low + (high - low + 1) / 2;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  return low;
}
template <typename F>
double binary_search_real(F check, double low, double high, int iter = 100) {
  FOR(iter) {
    double mid = (low + high) / 2;
    (check(mid) ? low : high) = mid;
  }
  return (low + high) / 2;
}

template <class T, class U>
bool chmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <class T, class U>
bool chmax(T &a, const U &b) {
  return a < b ? a = b, true : false;
}

template <typename T, typename U>
vc<T> cumsum(const vc<U> &A, int off = 1) {
  int N = A.size();
  vc<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}
template <typename T, typename... Vectors>
void concat(vc<T> &first, const Vectors &...others) {
  vc<T> &res = first;
  (res.insert(res.end(), others.begin(), others.end()), ...);
}