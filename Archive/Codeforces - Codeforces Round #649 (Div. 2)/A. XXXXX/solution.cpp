#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int n, x;
int a[N], s[N];

int solve() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  if (s[n] % x != 0) {
    return cout << n << "\n", 0;
  }
  int left = 0;
  int right = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] % x != 0) {
      left = i;
      break;
    }
  }
  rb(j, n, 1) if (a[j] % x != 0) {
    right = n - j + 1;
    break;
  }
  if (left == 0 && right == 0)
    cout << "-1\n";
  else {
    cout << n - min(left, right) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}