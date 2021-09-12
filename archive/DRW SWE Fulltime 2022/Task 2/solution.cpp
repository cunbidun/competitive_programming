#include <bits/stdc++.h>

using namespace std;

template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
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
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int solution(vector<int> &A, int K) {
  int N = A.size();
  if (N < K) {
    return -1;
  }
  sort(A.begin(), A.end(), [](auto f, auto s) { return f > s; });
  int mno = 1e9, mne = 1e9l, mxo = 0, mxe = 0;
  int s = 0;
  for (int i = 0; i < K; i++) {
    if (A[i] % 2 == 0) {
      mne = min(mne, A[i]);
    } else {
      mno = min(mno, A[i]);
    }
    s += A[i];
  }
  for (int i = K; i < N; i++) {
    if (A[i] % 2 == 0) {
      mxe = max(mxe, A[i]);
    } else {
      mxo = max(mxo, A[i]);
    }
  }
  if (s % 2 == 0) {
    return s;
  }
  int ans = -1;
  if (mno != 1e9 && mxe != 0) {
    ans = max(ans, s - mno + mxe);
  }
  if (mne != 1e9 && mxo != 0) {
    ans = max(ans, s - mne + mxo);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  cout << solution(a, K) << '\n';
}
