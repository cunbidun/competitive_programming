#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void radix_sort(vector<pair<ii, int>> &a) {
  int n = sz(a);
  vector<int> cnt(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i].first.first]++;
  }
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + cnt[i - 1];
  }
  vector<pair<ii, int>> new_a(n);
  for (int i = 0; i < n; i++) {
    new_a[p[a[i].first.first]] = a[i];
    p[a[i].first.first]++;
  }
  a = new_a;
}

int st[100200][19];
int f = 1;
int rmq(int l, int r) {
  int k = log2(r - l + 1);
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}

void solve(int tt) {
  if (f) {
    f = 0;
  } else {
    cout << "\n";
  }
  string s;
  cin >> s;
  if (tt == 1) {
    cout << s << "\n";
    return;
  }
  for (int i = 2; i <= tt; i++) {
    string x;
    cin >> x;
    s += char(i - 110) + x;
  }
  s += "$";
  int n = sz(s);
  vi p(n), c(n), lcp(n), num(n), appearance(n), ans(n);
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = {s[i], i};
  }

  sort(all(a));
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }

  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first) {
      c[p[i]] = c[p[i - 1]];
    } else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }

  int k = 0;
  while ((1 << k) < n) {
    vector<pair<ii, int>> a(n);
    for (int i = 0; i < n; i++) {
      int prev = (p[i] - (1 << k) + n) % n;
      a[i] = {{c[prev], c[p[i]]}, prev};
    }
    radix_sort(a);
    for (int i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    k++;
  }

  k = 0;
  for (int i = 0; i < n - 1; i++) {
    k = max(0, k - 1);
    while (s[i + k] == s[p[c[i] - 1] + k]) {
      k++;
    }
    lcp[c[i] - 1] = k;
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((int)s[i] < 90) {
      cnt++;
    }
    num[i] = cnt;
  }

  for (int j = 0; j <= 18; j++) {
    for (int i = 0; i <= n; i++) {
      st[i][j] = 1e9;
    }
  }

  for (int i = 1; i < n; i++) {
    st[i][0] = lcp[i];
  }

  for (int j = 1; j <= 18; j++) {
    for (int i = 1; i + (1 << (j - 1)) < n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }

  int l = tt;
  int r = l;
  cnt = 1;
  appearance[num[p[l]]]++;
  while (cnt < tt / 2 + 1) {
    r++;
    appearance[num[p[r]]]++;
    if (appearance[num[p[r]]] == 1) {
      cnt++;
    }
  }

  while (appearance[num[p[l]]] > 1) {
    appearance[num[p[l]]]--;
    l++;
  }

  int mx = rmq(l, r - 1);
  ans[p[l]] = mx;

  for (int i = r + 1; i < n; i++) {
    appearance[num[p[i]]]++;
    if (appearance[num[p[i]]] == 1) {
      cnt++;
    }
    while (l <= i) {
      if (cnt == tt / 2 + 1 && appearance[num[p[l]]] == 1) {
        break;
      }
      appearance[num[p[l]]]--;
      if (appearance[num[p[l]]] == 0) {
        cnt--;
      }
      l++;
    }
    int res = rmq(l, i - 1);

    if (mx <= res) {
      mx = res;
      ans[p[l]] = mx;
    }
  }

  if (mx == 0) {
    cout << "?\n";
    return;
  }

  set<string> string_list;
  for (int i = 0; i < n; i++) {
    if (ans[i] == mx) {
      string_list.insert(s.substr(i, mx));
    }
  }
  for (string entry : string_list) {
    cout << entry << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (1) {
    int t;
    cin >> t;
    if (t == 0) {
      break;
    }
    solve(t);
  }
}