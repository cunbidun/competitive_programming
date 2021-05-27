#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, k;
char a[N];
void solve() {
  cin >> n >> k;
  int ans = 0, cnt = 0;
  int ch = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 'W') {
      ans += 2;
      ch = 1;
    } else {
      cnt++;
    }
  }
  if (cnt <= k) {
    cout << 2 * n - 1 << "\n";
    return;
  }
  if (a[1] == 'W') {
    ans--;
  }
  vi l;
  int last = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == 'L' && a[i] == 'W') {
      if (last != 0) {
        l.push_back(i - last - 1);
      }
      ans--;
    }
    if (a[i - 1] == 'W' && a[i] == 'L') {
      last = i - 1;
    }
  }
  sort(all(l));
  for (int i : l) {
    // cout << i << " ";
    if (k >= i) {
      ans += i * 2 + 1;
      k -= i;
    }
  }
  // cout << "\n";
  ans += 2 * k;
  if (ch == 0) {
    ans--;
  }
  cout << max(ans, 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}