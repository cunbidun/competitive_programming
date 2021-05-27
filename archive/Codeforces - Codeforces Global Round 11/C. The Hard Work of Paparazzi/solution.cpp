#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, r, f[N], m[N];
struct c {
  int t, x, y;
} a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> r >> n;
  for (int i = 1; i <= n; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    a[i] = {t, x, y};
  }
  a[0] = {0, 1, 1};
  m[0] = 1;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[i].t - a[j].t >= 1000) {
        f[i] = max(m[j] + 1, f[i]);
        break;
      } else {
        if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t && f[j] > 0) {
          f[i] = max(f[j] + 1, f[i]);
        }
      }
    }
    m[i] = max(m[i - 1], f[i]);
  }
  cout << m[n] - 1 << "\n";
}