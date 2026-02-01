inline namespace IO {
#define SFINAE(x, ...)           \
  template <class, class = void> \
  struct x : std::false_type {}; \
  template <class T>             \
  struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto &is>
struct Reader {
  template <class T>
  void Impl(T &t) {
    if constexpr (DefaultI<T>::value)
      is >> t;
    else if constexpr (Iterable<T>::value) {
      for (auto &x : t) Impl(x);
    } else if constexpr (IsTuple<T>::value) {
      std::apply([this](auto &...args) { (Impl(args), ...); }, t);
    } else
      static_assert(IsTuple<T>::value, "No matching type for read");
  }
  template <class... Ts>
  void read(Ts &...ts) {
    ((Impl(ts)), ...);
  }
};

template <class... Ts>
void read(Ts &...ts) {
  Reader<cin>{}.read(ts...);
}
#define def(t, args...) \
  t args;               \
  read(args);

template <auto &os, bool debug, bool print_nd>
struct Writer {
  string comma() const { return debug ? "," : ""; }
  template <class T>
  constexpr char Space(const T &) const {
    return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n' : ' ';
  }
  template <class T>
  void Impl(T const &t) const {
    if constexpr (DefaultO<T>::value)
      os << t;
    else if constexpr (Iterable<T>::value) {
      if (debug) os << '{';
      int i = 0;
      for (auto &&x : t)
        ((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
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
    } else
      static_assert(IsTuple<T>::value, "No matching type for print");
  }
  template <class T>
  void ImplWrapper(T const &t) const {
    if (debug) os << "\033[0;31m";
    Impl(t);
    if (debug) os << "\033[0m";
  }
  template <class... Ts>
  void print(Ts const &...ts) const {
    ((Impl(ts)), ...);
  }
  template <class F, class... Ts>
  void print_with_sep(const std::string &sep, F const &f,
                      Ts const &...ts) const {
    ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
  }
  void print_with_sep(const std::string &) const { os << '\n'; }
};

template <class... Ts>
void print(Ts const &...ts) {
  Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}  // namespace IO

inline namespace Debug {
template <typename... Args>
void errn(Args... args) {
  Writer<cerr, true, true>{}.print_with_sep(" | ", args...);
}

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
#define SHOW(args...) err_prefix(__FUNCTION__, __LINE__, #args), errn(args)
#else
#define SHOW(args...)
#endif
}  // namespace Debug

inline namespace FileIO {
struct AutoIO {
  AutoIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);
  }
} auto_io;
}  // namespace FileIO

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }