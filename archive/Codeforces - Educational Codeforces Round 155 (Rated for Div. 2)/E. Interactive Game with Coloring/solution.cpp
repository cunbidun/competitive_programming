/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 10:47:46 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
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
namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> a(N + 1);
  vector<int> p(N + 1), edges(N + 1);
  for (int i = 2; i <= N; i++) {
    cin >> p[i];
    a[p[i]].push_back(i);
  }
  vector<int> lvl(N + 1);
  vector<int> subtree(N + 1);
  vector<int> root_children;
  lvl[1] = 0;
  auto dfs = yc([&](auto dfs_, int u) -> void {
    for (int v : a[u]) {
      if (u == 1) {
        subtree[v] = v;
        root_children.push_back(v);
      } else {
        subtree[v] = subtree[u];
      }
      lvl[v] = lvl[u] + 1;
      dfs_(v);
    }
  });
  dfs(1);

  vector<int> c(N + 1);
  map<vector<int>, int> res;

  auto part = [&](int num) -> bool {
    auto check = [&]() -> pair<bool, map<vector<int>, int>> {
      map<vector<int>, int> mp;
      vector<int> out(N + 1);
      vector<vector<int>> count(N + 1, vector<int>(4));
      for (int i = 2; i <= N; i++) {

        if (c[i] != 0) {
          out[i] = c[i];
          count[i][c[i]]++;
          count[p[i]][c[i]]++;
        }
      }
      for (int i = 2; i <= N; i++) {
        if (mp.find(count[i]) == mp.end()) {
          mp[count[i]] = out[i];
        }
        // if (num == 3) {
        //   debug() << imie(i) << imie(count[i]) << imie(out[i]);
        // }
        if (mp[count[i]] != out[i]) {
          // cout << "Fail at " << i << '\n';
          return {false, mp};
        }
      }
      return {true, mp};
    };

    for (int root_child : root_children) {
      int have_assignment = 0;
      for (int n = 1; n <= num; n++) {
        c[root_child] = n;
        for (int i = 2; i <= N; i++) {
          if (subtree[i] == root_child) {
            int diff = lvl[i] - lvl[root_child];
            c[i] = (n + diff) % num;
            if (c[i] == 0) {
              c[i] = num;
            }
            // cout << "got " << i << " in subtree " << subtree[i] << " color " << c[i] << '\n';
          }
        }
        // cout << "checking for " << root_child << ' ' << c[root_child] << '\n';
        auto e = check();
        if (e.first) {
          // cout << "pass" << '\n';
          res = e.second;
          have_assignment = 1;
          break;
        }
      }
      if (!have_assignment) {
        return false;
      }
    }
    return true;
  };

  int mxlvl = 1;
  int k = 0;
  for (int i = 1; i <= N; i++) {
    mxlvl = max(mxlvl, lvl[i]);
  }
  if (mxlvl == 1) {
    part(1);
    k = 1;
  } else if (part(2)) {
    k = 2;
  } else {
    k = 3;
    c.assign(N + 1, 0);
    res.clear();
    part(3);
  }
  cout << k << endl;
  for (int i = 2; i <= N; i++) {
    cout << c[i] << ' ';
  }
  cout << endl;
  while (1) {
    int x;
    cin >> x;
    if (x == 1 || x == -1) {
      return 0;
    } else {
      vector<int> color(4);
      for (int i = 1; i <= k; i++) {
        cin >> color[i];
      }
      // debug() << imie(color);
      cout << res[color] << endl;
    }
  }
}
