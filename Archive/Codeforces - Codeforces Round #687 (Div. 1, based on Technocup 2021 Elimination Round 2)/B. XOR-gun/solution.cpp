#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, a[N], s[N];

int cal(int i, int j) { return s[j] ^ s[i - 1]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] ^ a[i];
  }
  if (n > 70) {
    cout << 1 << "\n";
    return 0;
  }
  int ans = N;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= n - i; k++) {
        if (j == 1 && k == 1) {
          continue;
        } 
        if (cal(i - j + 1, i) > cal(i + 1, i + 1 + k - 1)) {
          ans = min(ans, j + k - 2);
        }
      }
    }
  }
  if (ans == N) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}