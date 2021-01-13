#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, a[N], cnt[2 * N], ch[2 * N];
void solve() {
  cin >> n;
  set<int> s;
  for (int i = 1; i <= 2 * n + 1; i++) {
    cnt[i] = 0;
    ch[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (ch[i]) {
      if (cnt[i] > 0) {
        ch[i + 1] = 1;
      }
    } else {
      if (cnt[i] > 0) {
        ch[i] = 1;
      }
      if (cnt[i] > 1) {
        ch[i + 1] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 2 * n + 1; i++) {
    ans += ch[i];
  }
  cout << ans << '\n';
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
