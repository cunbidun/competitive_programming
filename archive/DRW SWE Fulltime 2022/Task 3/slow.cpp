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

int cal(string &S) {
  int cnt = 1;
  string res = "";
  for (int i = 1; i < (int)S.size(); i++) {
    if (S[i] != S[i - 1]) {
      if (cnt != 1) {
        res += to_string(cnt) + S[i - 1];
      } else {
        res += S[i - 1];
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }
  if (cnt != 1) {
    res += to_string(cnt) + S.back();
  } else {
    res += S.back();
  }
  return res.size();
}
int solution(string &S, int K) {
  if (K == 0) {
    return cal(S);
  }
  int N = (int)S.size();
  int ans = 1e9;
  for (int i = 0; i + K - 1 < N; i++) {
    string tmp = "";
    for (int j = 0; j < i; j++) {
      tmp += S[j];
    }
    for (int j = i + K; j < N; j++) {
      tmp += S[j];
    }
    ans = min(ans, cal(tmp));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  int K;
  cin >> S >> K;
  cout << solution(S, K) << '\n';
};
