#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  ll n;
  cin >> n;
  ll m = n;
  int p = -1;
  vector<ll> l;
  int mx = 0;

  for (ll i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      l.push_back(i);
      n /= i;
      cnt++;
    }
    if (cnt > mx) {
      mx = cnt;
      p = i;
    }
  }

  if (n > 1) {
    if (1 > mx) {
      mx = 1;
      p = n;
    }
  }
  vector<ll> ans;
  for (int i = 1; i <= mx - 1; i++) {
    ans.push_back(p);
    m /= p;
  }
  if (m > 1) {
    ans.push_back(m);
  }
  cout << sz(ans) << "\n";
  for (ll i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}