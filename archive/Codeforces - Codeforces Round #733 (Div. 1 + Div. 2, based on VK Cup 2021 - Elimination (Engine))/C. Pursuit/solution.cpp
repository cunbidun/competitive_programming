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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> b[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int cur = N - (N / 4);
    int curA = 0, curB = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int> pqB;
    for (int i = 0; i < cur; i++) {
      curA += a[i];
      pq.push(a[i]);
      curB += b[i];
    }
    for (int i = cur; i < N; i++) {
      pqB.push(b[i]);
    }
    int bsz = cur;
    int ans = 0;
    while (curA < curB) {
      ans++;
      N++;
      cur = N - (N / 4);
      curA += 100;
      pq.push(100);
      pqB.push(0);
      if ((int)pq.size() > cur) {
        int val = pq.top();
        curA -= val;
        pq.pop();
      }
      if (!pqB.empty() && bsz < cur) {
        int val = pqB.top();
        curB += val;
        pqB.pop();
        bsz++;
      }
    }
    cout << ans << '\n';
  }
}
