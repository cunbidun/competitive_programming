#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
ll a[1001];
map<ll, int> cnt;
set<ii> used;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j || used.find({a[i], a[j]}) != used.end()) {
        continue;
      }
      used.insert({a[i], a[j]});
      map<ll, int> cur;
      cur[a[i]]++;
      cur[a[j]]++;
      ll ff = 1, ss = 1;
      int res = 2;
      while (1) {
        ll nxt = ff * a[i] + ss * a[j];
        if (abs(nxt) > 1e9 || cur[nxt] == cnt[nxt]) {
          break;
        }
        cur[nxt]++;
        ll tmp = ss;
        ss += ff;
        ff = tmp;
        res++;
      }
      ans = max(ans, res);
    }
  }
  cout << ans << "\n";
}
