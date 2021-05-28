#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
int N, T;

int mx[4 * MAX], mn[4 * MAX], lazy[4 * MAX];

void lazy_update(int i, int l, int r) {
  if (lazy[i] != 0) {
    mn[i] += lazy[i];
    mx[i] += lazy[i];
    if (l != r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
  }
  lazy[i] = 0;
}
void update(int i, int l, int r, int ql, int qr, int v) {
  lazy_update(i, l, r);
  if (r < ql || qr < l || qr < ql) {
    return;
  }
  if (ql <= l && r <= qr) {
    lazy[i] += v;
    lazy_update(i, l, r);
    return;
  }
  int m = (l + r) / 2;
  update(i * 2 + 1, l, m, ql, qr, v);
  update(i * 2 + 2, m + 1, r, ql, qr, v);
  mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
  mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
}
int get_min(int i, int l, int r, int ql, int qr) {
  lazy_update(i, l, r);
  if (r < ql || qr < l || qr < ql) {
    return 1e9;
  }
  if (ql <= l && r <= qr) {
    return mn[i];
  }
  int m = (l + r) / 2;
  return min(get_min(i * 2 + 1, l, m, ql, qr), get_min(i * 2 + 2, m + 1, r, ql, qr));
}
int get_max(int i, int l, int r, int ql, int qr) {
  lazy_update(i, l, r);
  if (r < ql || qr < l || qr < ql) {
    return -1e9;
  }
  if (ql <= l && r <= qr) {
    return mx[i];
  }
  int m = (l + r) / 2;
  return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
}
void update(int l, int r, int v) {
  update(0, 0, N - 1, l, r, v);
}
int get_min(int L, int R) {
  return get_min(0, 0, N - 1, L, R);
}
int get_max(int L, int R) {
  return get_max(0, 0, N - 1, L, R);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  T = N;
  int cur = 0;
  vector<char> V(N, 'a');
  while (T--) {
    char c;
    cin >> c;
    if (c == 'L') {
      if (cur > 0) {
        cur--;
      }
    } else if (c == 'R') {
      cur++;
    } else if (c == '(') {
      if (V[cur] == ')') {
        update(cur, N - 1, 2);
      } else if (V[cur] == 'a') {
        update(cur, N - 1, 1);
      }
      V[cur] = '(';
    } else if (c == ')') {
      if (V[cur] == '(') {
        update(cur, N - 1, -2);
      } else if (V[cur] == 'a') {
        update(cur, N - 1, -1);
      }
      V[cur] = ')';
    } else {
      if (V[cur] == '(') {
        update(cur, N - 1, -1);
      } else if (V[cur] == ')') {
        update(cur, N - 1, 1);
      }
      V[cur] = 'a';
    }
    if (get_min(0, N - 1) < 0 || get_min(N - 1, N - 1) != 0) {
      cout << -1 << '\n';
    } else {
      cout << get_max(0, N - 1) << '\n';
    }
  }
  cout << '\n';
}
