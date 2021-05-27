#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5e2 + 5;

int n;
vi l;
ll a[N][N];
vector<ll> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    l.push_back(x);
  }
  reverse(all(l));
  for (int k = 0; k < sz(l); k++) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[l[i]][l[j]] = min(a[l[i]][l[j]], a[l[i]][l[k]] + a[l[k]][l[j]]);
      }
    }
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        res += a[l[i]][l[j]];
      }
    }
    ans.push_back(res);
  }
  reverse(all(ans));
  for (ll i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
