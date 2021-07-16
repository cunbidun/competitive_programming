#include <bits/stdc++.h>

using namespace std;

template <class c>
struct rge { c b, e; };
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c>
  debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N), cnt(1e5 + 1);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  if (K == 2) {
    for (int i = 0; i < N; i++) {
      int tmp = 1;
      for (int j = 2; j * j <= a[i]; j++) {
        int count = 0;
        while (a[i] % j == 0) {
          a[i] /= j;
          count++;
        }
        if (count % 2 == 1) {
          tmp *= j;
        }
      }
      a[i] *= tmp;
    }
    long long ans = 0;
    // debug() << imie(a);
    for (int i = 0; i < N; i++) {
      ans += cnt[a[i]];
      cnt[a[i]]++;
    }
    cout << ans << '\n';
  } else {
    vector<long long> l;
    for (int i = 0; i < N; i++) {
      cnt[a[i]]++;
    }
    l.push_back(1);
    for (int i = 2; i <= 1e5; i++) {
      long long cur = 1;
      int f = 0;
      for (int j = 0; j < K; j++) {
        cur *= i;
        if (cur > 1e10) {
          f = 1;
          break;
        }
      }
      if (f) {
        break;
      }
      l.push_back(cur);
    }
    long long ans = 0;
    for (long long n : l) {
      for (int i : a) {
        if (n % i == 0 && (n / i) <= 1e5) {
          int tmp = cnt[(int)(n / i)];
          if (1LL * i * i == n) {
            tmp--;
          }
          ans += tmp;
        }
      }
    }
    cout << ans / 2 << '\n';
  }
}
