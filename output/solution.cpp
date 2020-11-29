#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5e5 + 5;
int n, k, a[N];
ll ans = 0;
vector<ll> l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  int p = 0;
  ll cur = 0;
  for (int i = 1; i <= n; i++) {
    p = i;
    ans += cur;
    cur += a[i];
    if (cur < 0) {
      break;
    }
  }
  if (cur >= 0) {
    cout << ans << "\n";
    return 0;
  }
  l.push_back(-cur);
  for (int i = p + 1; i <= n; i++) {
    l.push_back(-a[i]);
  }
  sort(all(l));
  reverse(all(l));
  cout << ans << "\n";
  for (ll i : l) {
    cout << i << " ";
  }
  cout << "\n";
}