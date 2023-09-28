/**
 *  author: cunbidun
 *  created: Tuesday, 2023-09-12 22:04:38 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>

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
    int N;
    cin >> N;
    vector<array<int, 4>> r(N);
    vector<array<int, 4>> event;
    for (int i = 0; i < N; i++) {
      cin >> r[i][0] >> r[i][2] >> r[i][1] >> r[i][3];
    }
    auto remove = [&](int x, int line) -> void {
      if (r[x][0] == r[x][1]) {
        assert(r[x][0] == line);
        r[x][0] = 0;
      } else {
        r[x][0] = 3 - line, r[x][1] = 3 - line;
      }
    };
    auto process = [&](int t1, int t2, int invert) -> void {
      if (invert) {
        swap(t1, t2);
      }
      set<int> removed;
      queue<int> s;
      for (int i = 0; i < (int)event.size(); i++) {
        auto e = event[i];
        if (e[2] != t1 && e[2] != t2) {
          continue;
        }
        if (r[e[3]][0] == 0) {
          continue;
        }
        int open = invert;
        if (e[1] == open) {
          s.push(e[3]);
        } else {
          // end
          if (!s.empty()) {
            if (s.front() == e[3]) {
              int id = s.front();
              s.pop();
              while (!s.empty()) {
                if (removed.count(s.front())) {
                  s.pop();
                } else {
                  break;
                }
              }
              if (e[2] != 3 || t1 == t2) {
                if (!s.empty()) {
                  if (!invert) {
                    r[id][3] = r[s.front()][2] - 1;
                  } else {
                    r[id][2] = r[s.front()][3] + 1;
                  }
                  if (r[id][3] < r[id][2]) {
                    removed.insert(id);
                    remove(id, t1);
                  }
                }
              }
            } else {
              removed.insert(e[3]);
              remove(e[3], t1);
            }
          }
        }
      }
    };
    vector<array<int, 2>> v = {
        {1, 1},
        {2, 2},
        {3, 3},
        {1, 3},
        {3, 1},
        {2, 3},
        {3, 2},
    };
    for (auto [t1, t2] : v) {
      event.clear();
      for (int i = 0; i < N; i++) {
        if (r[i][0] == 0) {
          continue;
        }
        int t;
        if (r[i][0] == r[i][1]) {
          t = r[i][0];
        } else {
          t = 3;
        }
        event.push_back({r[i][2], 0, t, i});
        event.push_back({r[i][3], 1, t, i});
      }
      int invert = t1 > t2;
      sort(event.begin(), event.end());
      if (invert) {
        assert(t1 > t2);
        reverse(event.begin(), event.end());
      }
      process(t1, t2, invert);
    }
    long long ans = 0;
    for (auto [x1, x2, y1, y2] : r) {
      if (x1 != 0) {
        ans += 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
      }
    }
    cout << ans << '\n';
    for (auto [x1, x2, y1, y2] : r) {
      if (x1 != 0) {
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
      } else {
        cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << '\n';
      }
    }
  }
}
