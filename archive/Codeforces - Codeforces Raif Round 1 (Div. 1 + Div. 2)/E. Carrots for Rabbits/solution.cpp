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
  vector<int> a(N);
  priority_queue<pair<long long, array<int, 2>>> pq;
#define v second[0]
#define c second[1]
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  auto cal = [](int x, int i) -> long long {
    int base = x / i;
    int u = x % i;
    return 1LL * base * base * (i - u) + 1LL * (base + 1) * (base + 1) * u;
  };

  for (int i = 0; i < N; i++) {
    pq.push({cal(a[i], 1) - cal(a[i], 2), {a[i], 1}});
  }
  for (int i = 1; i <= K - N; i++) {
    auto num = pq.top();
    pq.pop();
    pq.push({cal(num.v, num.c + 1) - cal(num.v, num.c + 2), {num.v, num.c + 1}});
  }
  vector<int> l;
  while (!pq.empty()) {
    auto num = pq.top();
    pq.pop();
    for (int i = 0; i < num.c; i++) {
      if (i < num.v % num.c) {
        l.push_back(num.v / num.c + 1);
      } else {
        l.push_back(num.v / num.c);
      }
    }
  }
  assert((int)l.size() == K);
  // debug() << imie(l);
  long long ans = 0;
  for (int i : l) {
    ans += 1LL * i * i;
  }
  cout << ans << '\n';
}
