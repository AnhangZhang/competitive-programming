#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = long double;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using vi = vector<ll>;
using vd = vector<db>;
using vb = vector<bool>;
using vs = vector<string>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template <class T> using pq_max = priority_queue<T>;
template <class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, n, ...) vector<vector<type>> name(n, vector<type>(__VA_ARGS__))
#define vvv(type, name, n, m, ...)                                                                                     \
  vector<vector<vector<type>>> name(n, vector<vector<type>>(m, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                 \
  vector<vector<vector<vector<type>>>> name(                                                                           \
      a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR1(a) for (ll _ = 0; _ < ll(a); _++)
#define FOR2(i, a) for (ll i = 0; i < ll(a); i++)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); i++)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define ROF1(a) for (ll i = (a) - 1; i >= ll(0); i--)
#define ROF2(i, a) for (ll i = (a) - 1; i >= ll(0); i--)
#define ROF3(i, a, b) for (ll i = (b) - 1; i >= ll(a); i--)
#define ROF4(i, a, b, c) for (ll i = (b) - 1; i >= ll(a); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define ROF(...) overload4(__VA_ARGS__, ROF4, ROF3, ROF2, ROF1)(__VA_ARGS__)

#define all(v) (v).begin(), (v).end()
#define si(v) ll(v.size())
#define stoi stoll

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

constexpr ll TEN(int x) { return x == 0 ? 1ll : TEN(x - 1) * 10; }

template <class T, class U> bool ckmax(T &a, const U &b) { return b > a ? a = b, true : false; }
template <class T, class U> bool ckmin(T &a, const U &b) { return b < a ? a = b, true : false; }
template <class T, class U> T SUM(const U &v) { return accumulate(v.begin(), v.end(), T{}); }
#define MIN(v) min_element(all(v))
#define MAX(v) max_element(all(v))
#define LB(v, x) lower_bound(all(v), x)
#define UB(v, x) upper_bound(all(v), x)
#define UNIQUE(v) sort(all(v)), v.erase(unique(all(v)), v.end())

template <class T, class Container, class Compare> T POP(priority_queue<T, Container, Compare> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <class T> T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

inline namespace IO {
#define SFINAE(x, ...)                                                                                                 \
  template <class, class = void> struct x : std::false_type {};                                                        \
  template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto &is> struct Reader {
  template <class T> void Impl(T &t) {
    if constexpr (DefaultI<T>::value) {
      is >> t;
    } else if constexpr (Iterable<T>::value) {
      for (auto &x : t) Impl(x);
    } else if constexpr (IsTuple<T>::value) {
      std::apply([this](auto &...args) { (Impl(args), ...); }, t);
    } else {
      static_assert(IsTuple<T>::value, "No matching type for read");
    }
  }
  template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};

template <class... Ts> void read(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define INT(...)                                                                                                       \
  int __VA_ARGS__;                                                                                                     \
  read(__VA_ARGS__)
#define LL(...)                                                                                                        \
  ll __VA_ARGS__;                                                                                                      \
  read(__VA_ARGS__);
#define STR(...)                                                                                                       \
  string __VA_ARGS__;                                                                                                  \
  read(__VA_ARGS__);
#define CHAR(...)                                                                                                      \
  char __VA_ARGS__;                                                                                                    \
  read(__VA_ARGS__);
#define DBL(...)                                                                                                       \
  db __VA_ARGS__;                                                                                                      \
  read(__VA_ARGS__);
#define VEC(type, name, size)                                                                                          \
  vector<type> name(size);                                                                                             \
  read(name);
#define VV(type, name, n, m)                                                                                           \
  vector<vector<type>> name(n, vector<type>(m));                                                                       \
  read(name);

template <auto &os, bool debug, bool print_nd> struct Writer {
  string comma() const { return debug ? "," : ""; }
  template <class T> constexpr char Space(const T &) const {
    return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
  }
  template <class T> void Impl(T const &t) const {
    if constexpr (DefaultO<T>::value) {
      os << t;
    } else if constexpr (Iterable<T>::value) {
      if (debug) os << '{';
      int i = 0;
      for (auto &&x : t) ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
      if (debug) os << '}';
    } else if constexpr (IsTuple<T>::value) {
      if (debug) os << '(';
      std::apply(
          [this](auto const &...args) {
            int i = 0;
            (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)), ...);
          },
          t);
      if (debug) os << ')';
    } else {
      static_assert(IsTuple<T>::value, "No matching type for print");
    }
  }
  template <class T> void ImplWrapper(T const &t) const {
    if (debug) os << "\033[0;31m";
    Impl(t);
    if (debug) os << "\033[0m";
  }
  template <class... Ts> void print(Ts const &...ts) const { ((Impl(ts)), ...); }
  template <class F, class... Ts> void print_with_sep(const std::string &sep, F const &f, Ts const &...ts) const {
    ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
  }
  void print_with_sep(const std::string &) const { os << '\n'; }
};

template <class... Ts> void print(Ts const &...ts) { Writer<cout, false, true>{}.print_with_sep(" ", ts...); }

template <typename... Args> void err(Args... args) { Writer<cerr, true, true>{}.print_with_sep(" | ", args...); }

void err_prefix(string func, int line, string args) {
  cerr << "\033[0;31m\u001b[1mDEBUG\033[0m"
       << " | "
       << "\u001b[34m" << func << "\033[0m"
       << ":"
       << "\u001b[34m" << line << "\033[0m"
       << " - "
       << "[" << args << "] = ";
}

#ifdef LOCAL
#define SHOW(...) err_prefix(__FUNCTION__, __LINE__, #__VA_ARGS__), err(__VA_ARGS__)
#else
#define SHOW(...)
#endif

struct IO_Init {
  IO_Init() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(20);
  }
} io_init;
} // namespace IO

void YES(bool t = true) { print(t ? "YES" : "NO"); }
void Yes(bool t = true) { print(t ? "Yes" : "No"); }
void Takahashi(bool t = true) { print(t ? "Takahashi" : "Aoki"); }
void Alice(bool t = true) { print(t ? "Alice" : "Bob"); }

int main() { ${0} }