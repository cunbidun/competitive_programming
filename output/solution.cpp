#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll; typedef vector<int> vi; typedef pair<int, int> ii;

const int N = 1e6 + 5;

int n, r, c, a[N], nxt[N][21];
string s[N];

int get_idx(int cur) {
  int res = cur;
  for (int i = 20; i >= 0; i--) {
    if (((r >> i) & 1) == 1) {
      res = nxt[res][i];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r >> c;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    a[i] = sz(s[i]);
  }
  int p = 0;
  int cur = 0;
  int cnt = 0;
  nxt[n + 1][0] = n + 1;
  for (int i = 1; i <= n; i++) {
    while (p <= n && cur + cnt - 1 <= c) {
      cur += a[++p];
      cnt++;
    }
    nxt[i][0] = p;

    cur -= a[i];
    cnt--;
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= n + 1; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }
  /* for (int i = 1; i <= n; i++) { */
  /*   cout << nxt[i][1] << "\n"; */
  /* } */
  int mx = 0;
  p = -1;
  for (int i = 1; i <= n; i++) {
    int j = get_idx(i);
    if (i == j) {
      continue;
    }
    if (j - i > mx) {
      mx = j - i;
      p = i;
    }
  }
  cur = 1;
  for (int i = p; i <= p + mx - 1;) {
    if (cur > r) {
      break;
    }
    int cur_length = sz(s[i]);
    cout << s[i++];
    while (i <= p + mx - 1) {
      if ((cur_length + 1 + sz(s[i])) > c) {
        break;
      }
      cur_length += 1 + sz(s[i]);
      cout << " " << s[i++];
    }
    cout << "\n";
    cur++;
  }
}
