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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    vector<vector<int>> b(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> b[i][j];
      }
    }
    auto check = [&](int bit) -> bool {
      vector<array<int, 2>> r(N);
      vector<array<int, 2>> c(M);
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (((b[i][j] >> bit) & 1) == 1) {
            c[j][0] += 1;
            c[j][1] = j;
          } else {
            r[i][0] += 1;
            r[i][1] = i;
          }
          // cout << ((b[i][j] >> bit) & 1) << ' ';
        }
        // cout << '\n';
      }
      sort(r.begin(), r.end());
      reverse(r.begin(), r.end());
      sort(c.begin(), c.end());
      reverse(c.begin(), c.end());
      int c_index = 0;
      int r_index = 0;
      set<int> removed_c;
      set<int> removed_r;
      while (c_index < M && r_index < N) {
        if ((int)removed_r.size() + c[c_index][0] == N) {
          removed_c.insert(c[c_index][1]);
          c_index++;
        } else if ((int)removed_c.size() + r[r_index][0] == M) {
          removed_r.insert(r[r_index][1]);
          r_index++;
        } else {
          break;
        }
      }

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (removed_c.find(j) == removed_c.end() && removed_r.find(i) == removed_r.end()) {
            if (((a[i][j] >> bit) & 1) != ((b[i][j] >> bit) & 1)) {
              return 1;
            }
          }
        }
      }
      return 0;
    };
    int f = 0;
    for (int bit = 0; bit <= 30; bit++) {
      f = check(bit);
      if (f) {
        break;
      }
    }
    if (f) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
}
