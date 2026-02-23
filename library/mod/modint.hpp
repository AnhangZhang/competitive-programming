#pragma once

template <int mod>
struct modint {
  static constexpr u32 umod = u32(mod);
  static_assert(umod < u32(1) << 31);
  u32 val;

  static modint raw(u32 v) {
    modint x;
    x.val = v;
    return x;
  }
  constexpr modint() : val(0) {}
  constexpr modint(u32 x) : val(x % umod) {}
  constexpr modint(u64 x) : val(x % umod) {}
  constexpr modint(u128 x) : val(x % umod) {}
  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x) {}
  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x) {}
  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x) {}
  bool operator<(const modint &other) const { return val < other.val; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += umod - p.val) >= umod) val -= umod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = u64(val) * p.val % umod;
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inv();
    return *this;
  }
  modint operator-() const { return modint::raw(val ? mod - val : u32(0)); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }

  modint inv() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(ll n) {
    if (n < 0) return inv().pow(-n);
    assert(n >= 0);
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
};

inline namespace IO {
template <int mod>
struct DefaultI<modint<mod>, std::void_t<>> : std::true_type {};

template <int mod>
std::istream &operator>>(std::istream &is, modint<mod> &x) {
  long long tmp;
  is >> tmp;
  x = modint<mod>(tmp);
  return is;
}

template <int mod>
struct DefaultO<modint<mod>, std::void_t<>> : std::true_type {};
template <int mod>
std::ostream &operator<<(std::ostream &os, const modint<mod> &x) {
  return os << x.val;
}
}  // namespace IO

using modint107 = modint<1000000007>;
using modint998 = modint<998244353>;