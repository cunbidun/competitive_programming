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

int cal(string S) {
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
  vector<pair<char, int>> list;
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (S[i] != S[i - 1]) {
      list.push_back({S[i - 1], cnt});
      cnt = 1;
    } else {
      cnt++;
    }
  }
  list.push_back({S.back(), cnt});
  vector<int> len(list.size());
  for (int i = 0; i < (int)list.size(); i++) {
    len[i] = (list[i].second == 1) ? 1 : to_string(list[i].second).size() + 1;
    if (i != 0) {
      len[i] += len[i - 1];
    }
  }

  int ans = min(cal(S.substr(K)), cal(S.substr(0, S.size() - K)));
  int p0 = -1, p1 = -1;
  int left = 0;
  int right = 0;
  for (int i = 1; i + K - 1 < N - 1; i++) {
    int l = i - 1;
    int r = i + K;
    while (left < l + 1) {
      p0++;
      left += list[p0].second;
    }
    while (right < r + 1) {
      p1++;
      right += list[p1].second;
    }
    int res = 0;
    if (p0 != 0) {
      res += len[p0 - 1];
    }
    if (p1 != (int)list.size() - 1) {
      res += len.back() - len[p1];
    }
    int lr = l + 1 - (left - list[p0].second);
    int rr = (right - 1) - r + 1;
    if (S[l] == S[r]) {
      res += 1;
      if (lr + rr > 1) {
        res += to_string(lr + rr).size();
      }
    } else {
      res += 2;
      if (lr > 1) {
        res += to_string(lr).size();
      }
      if (rr > 1) {
        res += to_string(rr).size();
      }
    }
    ans = min(ans, res);
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
