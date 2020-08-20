#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

ll s, tot;
int n;
vector<pair<int, ll>> a[N];
priority_queue<tuple<ll, ll, int>> pq;

int dfs(int u, int l = 1) {
  int cnt = (u != 1 && sz(a[u]) == 1);
  ll to_par = 0;
  for (pair<int, ll> v : a[u]) {
    if (v.first != l) {
      int children = dfs(v.first, u);
      cnt += children;
    } else {
      to_par = v.second;
    }
  }
  if (u != 1) {
    pq.push({to_par * cnt - (to_par / 2) * cnt, to_par / 2, cnt});
    tot += to_par * cnt;
  }
  return cnt;
}

void reset() {
  tot = 0;
  for (int i = 1; i <= n; i++) {
    a[i].clear();
  }
  while (!pq.empty()) {
    pq.pop();
  }
}

int solve() {
  cin >> n >> s;
  reset();
  for (int i = 1; i < n; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  dfs(1);
  int ans = 0;
  while (tot > s) {
    tuple<ll, ll, int> t = pq.top();
    pq.pop();
    tot -= get<0>(t);
    ll to_par = get<1>(t);
    int cnt = get<2>(t);
    pq.push({to_par * cnt - (to_par / 2) * cnt, to_par / 2, cnt});
    ans++;
  }
  cout << ans << "\n";
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