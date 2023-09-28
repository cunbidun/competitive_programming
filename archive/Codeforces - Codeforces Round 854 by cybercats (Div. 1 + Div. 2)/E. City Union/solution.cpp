/**
 *  author: cunbidun
 *  created: Saturday, 2023-09-02 17:39:14 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(M));
    vector<vector<int>> visisted(N, vector<int>(M));
    int h_mx = -1, h_mn = 100, v_mx = -1, v_mn = 100;
    auto dfs = yc([&](auto _dfs, int x, int y) -> void {
      int dx[] = {0, 0, 1, -1};
      int dy[] = {1, -1, 0, 0};
      visisted[x][y] = 1;
      h_mx = max(y, h_mx);
      h_mn = min(y, h_mn);
      v_mx = max(x, v_mx);
      v_mn = min(x, v_mn);
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || a[nx][ny] == 0 || visisted[nx][ny]) {
          continue;
        }
        _dfs(nx, ny);
      }
    });

    auto fill = [&]() -> void {
      for (int k = 0; k < 2; k++) {
        for (int i = 0; i < N; i++) {
          int first = -1, last = -1;
          for (int j = 0; j < M; j++) {
            if (a[i][j] == 1) {
              last = j;
              if (first == -1) {
                first = j;
              }
            }
          }
          if (first != -1) {
            for (int j = first; j <= last; j++) {
              a[i][j] = 1;
            }
          }
        }

        for (int j = 0; j < M; j++) {
          int first = -1, last = -1;
          for (int i = 0; i < N; i++) {
            if (a[i][j] == 1) {
              last = i;
              if (first == -1) {
                first = i;
              }
            }
          }
          if (first != -1) {
            for (int i = first; i <= last; i++) {
              a[i][j] = 1;
            }
          }
        }
      }
    };

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        char x;
        cin >> x;
        if (x == '#') {
          a[i][j] = 1;
        } else {
          a[i][j] = 0;
        }
      }
    }

    fill();

    vector<array<int, 4>> udlr;
    vector<int> tmp1, tmp2;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (a[i][j] && !visisted[i][j]) {
          h_mx = -1, h_mn = 100, v_mx = -1, v_mn = 100;
          dfs(i, j);
          tmp1.push_back(v_mn);
          tmp1.push_back(v_mx);
          tmp2.push_back(h_mn);
          tmp2.push_back(h_mx);
        }
      }
    }

    if (tmp1.size() == 4) {
      sort(tmp1.begin(), tmp1.end());
      sort(tmp2.begin(), tmp2.end());
      a[tmp1[1]][tmp2[1]] = 1;
      a[tmp1[1]][tmp2[2]] = 1;
      fill();
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << (a[i][j] ? '#' : '.');
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
