#include <bits/stdc++.h>

using namespace std;

template <class c> struct rge {
  c b, e;
};
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
    int N;
    cin >> N;
    int MX = N;
    vector<int> cnt(MX + 1);
    vector<int> num_dividend(MX + 1);
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }

    vector<int> p;
    for (int i = 1; i <= MX; i++) {
      for (int j = i; j <= MX; j += i) {
        num_dividend[i] += cnt[j];
      }
    }
    vector<long long> dp(MX + 1);

    for (int i = MX; i >= 1; i--) {
      dp[i] = 1LL * num_dividend[i] * (num_dividend[i] - 1) / 2;
      for (int j = i + i; j <= MX; j += i) {
        dp[i] -= dp[j];
      }
    }

    vector<int> w(MX + 1);
    for (int i = 1; i <= MX; i++) {
      for (int j = i; j <= MX; j += i) {
        if (cnt[i]) {
          w[j] = 1;
        }
      }
    }
    long long total = 1LL * N * (N - 1) / 2;
    // debug() << imie(w);
    for (int i = 1; i <= MX; i++) {
      if (w[i]) {
        total -= dp[i];
      }
    }
    cout << total << '\n';
  }
}
