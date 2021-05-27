#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<int, ii> iii;
ll mod = 1e9 + 7;
ii a[100005];
stack<ii> s;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].st;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].nd;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll len = a[i].nd;
    while (!s.empty() && s.top().st >= a[i].st) {
      ii cur = s.top();
      s.pop();
      ll w = cur.nd;
      ll h = cur.st;
      ll tmp = w * (w + 1) / 2 % mod;
      ll tmp2 = h * (h + 1) / 2 % mod;
      ll tmp3 = tmp * tmp2 % mod;
      ans = (ans + tmp3) % mod;
      h = a[i].st;
      tmp = w * (w + 1) / 2 % mod;
      tmp2 = h * (h + 1) / 2 % mod;
      tmp3 = tmp * tmp2 % mod;
      ans = (ans - tmp3) % mod;
      len = (len + w) % mod;
      // cout<<ans<<endl;
    }
    s.push(ii(a[i].st, len));
  }
  cout<<ans<<endl;
  ll len = 0;
  while (!s.empty()) {
    ii cur = s.top();
    s.pop();
    ll tmp1 = 0;
    if (!s.empty()) {
      tmp1 = s.top().st;
    }
    len = (len + cur.nd) % mod;
    ll w = len;
    ll h = cur.st;
    // cout<<w<<' '<<h<<endl;
    ll tmp = w * (w + 1) / 2 % mod;
    ll tmp2 = h * (h + 1) / 2 % mod;
    ll tmp3 = tmp * tmp2 % mod;
    ans = (ans + tmp3) % mod;
    h = tmp1;
    // cout<<w<<' '<<h<<endl;
    tmp = w * (w + 1) / 2 % mod;
    tmp2 = h * (h + 1) / 2 % mod;
    tmp3 = tmp * tmp2 % mod;
    ans = (ans - tmp3) % mod;
    // cout<<ans<<endl;
  }
  cout << ans << endl;
}