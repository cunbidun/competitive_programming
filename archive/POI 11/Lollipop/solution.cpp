#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  int sp = 0;
  int cnt_l = 0, cnt_r = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    cnt_l++;
    if (S[i] == 'W') {
      break;
    }
  }
  for (int i = (int)S.size() - 1; i >= 0; i--) {
    cnt_r++;
    if (S[i] == 'W') {
      break;
    }
  }
  if (cnt_l < cnt_r) {
    sp = 1;
    reverse(S.begin(), S.end());
  }
  S = "*" + S;
  vector<vector<int>> p(2);
  vector<int> list;
  vector<int> s(N + 1);
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (S[i] == 'W') {
      cnt = 1 - cnt;
      p[cnt].push_back(i);
      list.push_back(i);
      s[i] = s[i - 1] + 1;
    } else {
      s[i] = s[i - 1] + 2;
    }
  }
  vector<int> left(N + 1, 0);
  vector<int> right(N + 1, 0);
  cnt = 0;
  int mx = 0;
  int mx_pos = -1;
  for (int i = 1; i <= N; i++) {
    if (S[i] == 'T') {
      cnt++;
    } else {
      left[i] = cnt;
      if (mx < cnt) {
        mx = cnt;
        mx_pos = i - cnt;
      }
      cnt = 0;
    }
  }
  if (mx < cnt) {
    mx = cnt;
    mx_pos = N + 1 - cnt;
  }
  cnt = 0;
  for (int i = N; i >= 1; i--) {
    if (S[i] == 'T') {
      cnt++;
    } else {
      if (mx < cnt) {
        mx = cnt;
      }
      right[i] = cnt;
      cnt = 0;
    }
  }
  if (mx < cnt) {
    mx = cnt;
    mx_pos = 1;
  }
  // debug() << imie(l);
  // debug() << imie(r);
  // cout << mx << ' ' << mx_pos << '\n';
  auto get_out_sum = [&](int i, int j) -> int {
    return 2 * (left[i] + right[j]) + s[j] - s[i - 1];
  };
  auto get_right_sum = [&](int j) -> int {
    return 2 * right[j] + s[j];
  };

  while (Q--) {
    int x;
    cin >> x;
    int par = x % 2;
    if (x % 2 == 0 && x <= 2 * mx) {
      if (!sp) {
        cout << mx_pos << ' ' << mx_pos + x / 2 - 1 << '\n';
      } else {
        cout << N - (mx_pos + x / 2 - 1) + 1 << ' ' << N - mx_pos + 1 << '\n';
      }
      continue;
    }
    int l = 0, r = (int)(p[par].size()) - 1;
    if (l > r || get_right_sum(p[par][r]) < x) {
      cout << "NIE\n";
      continue;
    }
    while (l < r) {
      int m = (l + r) / 2;
      if (get_right_sum(p[par][m]) < x) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    int sz = (l + 1) * 2 - par;
    r = sz / 2;
    l = 0;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (get_out_sum(list[m], list[sz - 1 - m]) >= x) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    int rm = (get_out_sum(list[l], list[sz - 1 - l]) - x) / 2;
    int c_l = list[l] - left[list[l]];
    int c_r = list[sz - 1 - l] + right[list[sz - 1 - l]];

    c_l += min(left[list[l]], rm);
    rm -= min(left[list[l]], rm);

    c_r -= min(right[list[sz - 1 - l]], rm);
    rm -= min(right[list[sz - 1 - l]], rm);

    if (!sp) {
      cout << c_l << ' ' << c_r << '\n';
    } else {
      cout << N - c_r + 1 << ' ' << N - c_l + 1 << '\n';
    }
  }
}
