#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, cnt[N];
ii a[N];

bool cmp(ii A, ii B) {
  return A.first > B.first;
}

void solve() {
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    cin >> a[i].first;
    ans += a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    cnt[u]++;
    cnt[v]++;
  }
  sort(a + 1, a + 1 + n, cmp);
  cout << ans << " ";
  for (int i = 1; i <= n; i++) {
    while (cnt[a[i].second] > 1) {
      ans += a[i].first;
      cout << ans << " ";
      cnt[a[i].second]--;
    }
  }
  cout << "\n";
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
