#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N], cnt[N];

void solve() {
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mn = 2 * N;
  int p = -1;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] == 1 && mn > a[i]) {
      mn = min(a[i], mn);
      p = i;
    }
  }
  cout << p << "\n";
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