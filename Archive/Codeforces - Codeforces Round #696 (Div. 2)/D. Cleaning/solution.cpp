#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
const ll INF = 2e15;
int n;
ll a[N], l[N], r[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l[i] = r[i] = 0;
  }
  r[n + 1] = 0;
  l[1] = a[1];
  for (int i = 2; i <= n; i++) {
    l[i] = a[i] - l[i - 1];
    if (l[i] < 0) {
      l[i] = INF;
    }
  }
  if (l[n] == 0) {
    cout << "YES\n";
    return;
  }
  r[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    r[i] = a[i] - r[i + 1];
    if (r[i] < 0) {
      r[i] = INF;
    }
  }
  for (int i = 1; i < n; i++) {
    ll cur = r[i + 2];
    ll c[5];
    c[1] = l[i - 1];
    c[2] = a[i + 1];
    c[3] = a[i];
    c[4] = cur;
    ll d = c[1];
    int f = 0;
    for (int i = 2; i <= 4; i++) {
      d = c[i] - d;
      if (d < 0) {
        f = 1;
        break;
      }
    }
    if (!f && d == 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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
