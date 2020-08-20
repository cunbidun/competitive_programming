#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

// Code below this line will be copied.

#define st first
#define nd second
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
ll a[100005];
ll s[100005];

int main() {
  ll n, d, m;
  cin >> n >> d >> m;
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  ll bear = 0;
  for (ll i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
    if (a[i] <= m)
      bear++;
    //cout<<i<<' '<<s[i]<<endl;
  }
  ll ans = 0;
  ll unbear = n - bear;
  for (ll i = 0; i <= n; i++) {
    ll rem_pos = n - i;
    ll cur = 0;
    bool ok = 1;
    if (i % d == 0) {
      ll take = i / d;
      if (n - i > take) {
        take += 1;
        if (take > unbear)
          take--;
        if (take > unbear) {
          ok = 0;
          continue;
        }
        ll ban_unbear = unbear - take;
        if (ban_unbear > i) {
          ok = 0;
          continue;
        }
        ll ban_bear = i - ban_unbear;
        if (ban_bear > bear) {
          ok = 0;
          continue;
        }
        ll all_take = unbear - ban_unbear + bear - ban_bear;
        if (all_take > rem_pos) {
          ok = 0;
          continue;
        }
        cur = s[bear] - s[ban_bear] + s[n] - s[ban_unbear + bear];
      } else {
        ll ban_unbear = unbear - take;
        if (take > unbear) {
          ok = 0;
          continue;
        }
        if (ban_unbear > i) {
          ok = 0;
          continue;
        }
        ll ban_bear = i - ban_unbear;
        if (ban_bear > bear) {
          ok = 0;
          continue;
        }
        ll all_take = unbear - ban_unbear + bear - ban_bear;
        if (all_take > rem_pos) {
          ok = 0;
          continue;
        }
        cur = s[bear] - s[ban_bear] + s[n] - s[ban_unbear + bear];
      }
    } else {
      ll take = i / d + 1;
      ll ban_unbear = unbear - take;
      if (take > unbear) {
        ok = 0;
        continue;
      }
      if (ban_unbear > i) {
        ok = 0;
        continue;
      }
      ll ban_bear = i - ban_unbear;
      if (ban_bear > bear) {
        ok = 0;
        continue;
      }
      ll all_take = unbear - ban_unbear + bear - ban_bear;
      if (all_take > rem_pos) {
        ok = 0;
        continue;
      }
      cur = s[bear] - s[ban_bear] + s[n] - s[ban_unbear + bear];
    }
    if (ok) {
      //cout<<i<<' '<<cur<<endl;
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
}
