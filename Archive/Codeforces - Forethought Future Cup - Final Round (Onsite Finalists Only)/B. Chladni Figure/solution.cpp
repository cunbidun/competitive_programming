#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;

int n, m;
vector<int> s;
int p[N], c[N];

void radix_sort(vector<pair<ii, int>> &a) {
  int n = sz(a);
  vector<pair<ii, int>> new_a(n);
  vi cnt(n), pos(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i].first.first]++;
  }
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    new_a[pos[a[i].first.first]] = a[i];
    pos[a[i].first.first]++;
  }
  a = new_a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    s.push_back(1);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    int dis = min(abs(u - v), n - abs(u - v));
    s[u - 1] = (1LL * dis * dis + 1LL * s[u - 1] + 1) % (int)(1e9 + 7);
    s[v - 1] = (1LL * dis * dis + 1LL * s[v - 1] + 1) % (int)(1e9 + 7);
  }
  vector<int> t = s;
  for (int i = 0; i < n - 1; i++) {
    s.push_back(s[i]);
  }
  s.erase(s.begin());
  s.push_back(0);
  n = sz(s);
	
  vector<pair<int, int>> a(n);
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
      a[i] = {{c[(p[i] - (1 << k) + n) % n], c[p[i]]}, (p[i] - (1 << k) + n) % n};
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

  int l = 1, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    int val = 0;

    for (int i = 0; i < sz(t); i++) {
      if (i + p[m] == sz(s)) {
        val = -1;
        break;
      }
      if (s[i + p[m]] < t[i]) {
        val = -1;
        break;
      } else if (s[i + p[m]] > t[i]) {
        val = 1;
        break;
      }
    }

    if (val == -1) {
      l = m + 1;
    } else if (val == 1) {
      r = m - 1;
    } else {
      l = m,
      r = m;
    }
  }

  if (p[l] + sz(t) - 1 > sz(s)) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < sz(t); i++) {
    if (s[i + p[l]] != t[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}