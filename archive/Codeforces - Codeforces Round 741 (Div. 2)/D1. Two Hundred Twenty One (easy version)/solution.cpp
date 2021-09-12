#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, Q;
    cin >> N >> Q;
    vector<int> n, p;
    vector<vector<int>> s(2, vector<int>(N + 1));
    vector<vector<int>> nxt(N + 1, vector<int>(2, -1));

    string S = "*";
    for (int i = 1; i <= N; i++) {
      char x;
      cin >> x;
      S += x;
      s[0][i] = s[0][i - 1];
      s[1][i] = s[1][i - 1];
      if (x == '-') {
        n.push_back(i);
      } else {
        p.push_back(i);
        s[i % 2][i] = s[i % 2][i - 1] + 1;
      }
    }

    if (S[N] == '-') {
      nxt[N][0] = N;
    } else {
      nxt[N][1] = N;
    }
    for (int i = N - 1; i >= 1; i--) {
      nxt[i][0] = nxt[i + 1][0];
      nxt[i][1] = nxt[i + 1][1];
      if (S[i] == '-') {
        nxt[i][0] = i;
      } else {
        nxt[i][1] = i;
      }
    }
    auto cal = [&](int l, int r, int o, int pos) -> int {
      // cout << l << ' ' << r << ' ' << o << ' ' << pos << '\n';
      if (pos < l || r < pos) {
        return s[o][r] - s[o][l - 1];
      }
      return s[o][pos] - s[o][l - 1] + s[1 - o][r] - s[1 - o][pos];
    };

    while (Q--) {
      int l, r;
      cin >> l >> r;
      int x = cal(l, r, l % 2, -1);
      int x_p = cal(l, r, 1 - l % 2, -1);
      vector<int> v;
      if (x + x_p == (r - l + 1)) {
        if ((r - l + 1) % 2 == 1) {
          v.push_back(l);
        }
      } else {
        int n_o = (r - l + 1) / 2;
        int n_e = (r - l + 1) / 2;
        n_o += ((r - l + 1) % 2);
        int y = n_o - x;
        int y_p = n_e - x_p;
        int pos = -1;

        if ((y + y_p) % 2 == 1) {
          pos = nxt[l][0];
          v.push_back(nxt[l][0]);
          x = cal(l, r, l % 2, pos);
          x_p = cal(l, r, 1 - l % 2, pos);
        }

        if (x != x_p) {
          int lo = l, hi = r;
          while (lo < hi) {
            int m = (lo + hi) / 2;
            int even = cal(l, m, l % 2, pos);
            int odd = cal(l, m, 1 - l % 2, pos);
            if (max(even, odd) <= min(x, x_p)) {
              lo = m + 1;
            } else {
              hi = m;
            }
          }

          if ((x + x_p) % 2) {
            v.push_back(lo);
          } else {
            v.push_back(lo);
            v.push_back(nxt[lo + 1][1]);
          }
        }
      }

      cout << v.size() << '\n';
    }
  }
}
