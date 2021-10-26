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

class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    cerr << expression << endl;
    int N = expression.size();
    vector<int> res;
    for (int i = 0; i < N; i++) {
      if (!('0' <= expression[i] && expression[i] <= '9')) {
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right = diffWaysToCompute(expression.substr(i + 1));
        for (int l : left) {
          for (int r : right) {
            if (expression[i] == '+') {
              res.push_back(l + r);
            } else if (expression[i] == '-') {
              res.push_back(l - r);
            } else {
              res.push_back(l * r);
            }
          }
        }
      }
    }
    if (res.empty()) {
      res.push_back(stoi(expression));
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  for (int i : Solution().diffWaysToCompute(s)) {
    cout << i << ' ';
  }
  cout << '\n';
}
