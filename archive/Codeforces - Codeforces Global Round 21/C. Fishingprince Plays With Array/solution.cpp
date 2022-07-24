#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, K, M;
    cin >> N >> M;
    vector<array<long long, 2>> a, b;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      int total = 1;
      while (x % M == 0) {
        x /= M;
        total *= M;
      }
      a.push_back({x, total});
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
      int x;
      cin >> x;
      int total = 1;
      while (x % M == 0) {
        x /= M;
        total *= M;
      }
      b.push_back({x, total});
    }
    vector<array<long long, 2>> A, B;
    long long cur = a[0][1];
    for (int i = 1; i < (int)a.size(); i++) {
      if (a[i][0] == a[i - 1][0]) {
        cur += a[i][1];
      } else {
        A.push_back({a[i - 1][0], cur});
        cur = a[i][1];
      }
    }
    A.push_back({a[N - 1][0], cur});

    cur = b[0][1];
    for (int i = 1; i < (int)b.size(); i++) {
      if (b[i][0] == b[i - 1][0]) {
        cur += b[i][1];
      } else {
        B.push_back({b[i - 1][0], cur});
        cur = b[i][1];
      }
    }
    B.push_back({b[K - 1][0], cur});

    // debug() << imie(A);
    // debug() << imie(a);
    // debug() << imie(B);
    // debug() << imie(b);

    if (A.size() != B.size()) {
      cout << "No\n";
    } else {
      int f = 0;
      for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] != B[i]) {
          f = 1;
          break;
        }
      }
      if (f) {
        cout << "No\n";
      } else {
        cout << "Yes\n";
      }
    }
  }
}
