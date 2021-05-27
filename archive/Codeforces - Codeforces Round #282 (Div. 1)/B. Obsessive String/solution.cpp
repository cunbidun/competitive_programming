#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
template <typename T>
class Modular {
public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U &x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U &x) {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type &operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular &operator+=(const Modular &other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }
  Modular &operator-=(const Modular &other) {
    if ((value -= other.value) < 0) 
      value += mod();
    return *this;
  }
  template <typename U>
  Modular &operator+=(const U &other) { return *this += Modular(other); }
  template <typename U>
  Modular &operator-=(const U &other) { return *this -= Modular(other); }
  Modular &operator++() { return *this += 1; }
  Modular &operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type &operator*=(const Modular &rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &operator*=(const Modular &rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U> &abs(const Modular<U> &v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

private:
  Type value;
};

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T> &number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number) {
  return to_string(number());
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number) {
  return stream << number();
}

template <typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
string s;
int p[N], c[N], ch[N];
Mint until[N], end_at[N], total[N];

void radix_sort(vector<pair<ii, int>> &a) {
  int n = sz(a);
  vector<pair<ii, int>> new_a(n);
  vi cnt(n), pos(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i].first.first]++;
  }
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    new_a[pos[a[i].first.first]] = a[i];
    pos[a[i].first.first]++;
  }
  a = new_a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  s += '$';
  int n = sz(s);

  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = {s[i], i};
  }
  sort(all(a));
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first) {
      c[p[i]] = c[p[i - 1]];
    } else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }

  int k = 0;
  while ((1 << k) < n) {
    vector<pair<ii, int>> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = {{c[(p[i] - (1 << k) + n) % n], c[p[i]]}, (p[i] - (1 << k) + n) % n};
    }
    radix_sort(a);
    for (int i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    k++;
  }

  string t;
  cin >> t;

  int l = 1, r = n - 1;
  while (l != r) {
    int m = (l + r) / 2;
    if (s.substr(p[m], sz(t)) >= t) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  if (s.substr(p[l], sz(t)) != t) {
    cout << 0 << "\n";
    return 0;
  }
  int l0 = l;
  l = 1;
  r = n - 1;
  while (l != r) {
    int m = (l + r + 1) / 2;
    if (s.substr(p[m], sz(t)) <= t) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  for (int i = l0; i <= l; i++) {
    ch[p[i] + sz(t)] = 1;
  }

  s = '*' + s;
  s = s.substr(0, sz(s) - 1);
  n = sz(s) - 1;

  for (int i = sz(t); i <= n; i++) {
    if (ch[i]) {
      end_at[i] += i - sz(t) + 1;
      end_at[i] += total[i - sz(t)];
    } else {
      end_at[i] = end_at[i - 1];
    }
    until[i] = until[i - 1] + end_at[i];
    total[i] = total[i - 1] + until[i];
  }
  cout << until[n] << "\n";
}