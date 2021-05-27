#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;
int n;
int a[N];
int solve() {
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      ans += a[i];
    }
  }

  vi o, e;
  for (int i = 1; i < n; i += 2) {
    o.push_back(a[i] - a[i - 1]);
  }
  for (int i = 1; i < n - 1; i += 2) {
    e.push_back(a[i] - a[i + 1]);
  }
  ll cur = 0;
  ll add = 0;
  for (int i = 0; i < sz(o); i++) {
    cur += o[i];
    if (cur < 0) {
      cur = 0;
    }
    add = max(add, cur);
  }
   cur = 0;
	for (int i = 0; i < sz(e); i++) {
    cur += e[i];
    if (cur < 0) {
      cur = 0;
    }
    add = max(add, cur);
  }
  cout << ans + add << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}