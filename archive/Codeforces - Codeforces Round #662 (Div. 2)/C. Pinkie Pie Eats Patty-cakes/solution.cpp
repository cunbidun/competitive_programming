#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, a[N], cnt[N], tmp[N], pos[N];

vi l;
map<int, int> mp;

void compress() {
  sort(all(l));
  l.resize(distance(l.begin(), unique(all(l))));
  for (int i : l) {
    mp[i] = sz(mp) + 1;
  }
}

bool check(int m) {
  int num = (n + m - 1) / m;
  if (num < cnt[1] || m > sz(l)) {
    return 0;
  }
  int r = n % m;
  if (r == 0) {
    r = m;
  }
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == num) {
      tmp++;
    }
  }
  return tmp <= r;
}

void solve() {
  cin >> n;
  mp.clear();
  l.clear();
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    cin >> a[i];
    l.push_back(a[i]);
  }
  compress();
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
    cnt[a[i]]++;
  }
  sort(cnt + 1, cnt + n + 1, greater<int>());
  int l = 1, r = n - 1;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}