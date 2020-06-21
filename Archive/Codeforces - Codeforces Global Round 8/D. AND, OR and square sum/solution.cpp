#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;
const int INF = 2e9;

int n;
ll a[N];
int cnt[25];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= 20; j++) {
      if (((x >> j) & 1) == 1) {
        cnt[j]++;
      }
    }
  }
  for (int i = 0; i <= 20; i++) {
    for (int j = 1; j <= cnt[i]; j++) {
      a[j] += (1LL << i);
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * a[i];
  }
  cout << ans << "\n";
}