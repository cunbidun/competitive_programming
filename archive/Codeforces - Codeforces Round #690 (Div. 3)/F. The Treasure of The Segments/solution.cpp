#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, ls[2 * N], rs[2 * N];
ii a[N];

vi l;
map<int, int> mp;
void compress() {
  sort(all(l));
  l.resize(distance(l.begin(), unique(all(l))));
  for (int i : l) {
    mp[i] = sz(mp) + 1;
  }
}

bool cmp(ii A, ii B) {
  return A.second < B.second;
}

void solve() {
  l.clear();
  mp.clear();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    l.push_back(a[i].first);
    l.push_back(a[i].second);
  }
  compress();
  for (int i = 1; i <= n; i++) {
    a[i].first = mp[a[i].first];
    a[i].second = mp[a[i].second];
  }
  int cur = n;
  rs[sz(mp) + 1] = 0;
  sort(a + 1, a + 1 + n);
  for (int i = sz(mp); i >= 1; i--) {
    rs[i] = rs[i + 1];
    while (cur > 0 && a[cur].first >= i) {
      rs[i]++;
      cur--;
    }
  }
  cur = 1;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= sz(mp); i++) {
    ls[i] = ls[i - 1];
    while (cur <= n && a[cur].second <= i) {
      ls[i]++;
      cur++;
    }
  }
  int ans = N;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, ls[a[i].first - 1] + rs[a[i].second + 1]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
