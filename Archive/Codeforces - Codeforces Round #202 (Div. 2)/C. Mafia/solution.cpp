#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  ll f = 0;
  for (int i = 1; i <= n; i++) {
    f += mx - a[i];
  }
  if (f > mx) {
    cout << mx << "\n";
    return 0;
  }
  ll cur = mx - f;
  cout << f + cur + (cur + n - 2) / (n - 1) << "\n";
}
