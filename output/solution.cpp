#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;
const int INF = 2e9;

int a[N];
int n, k;
int check(int x) {
  int cnt = 0;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if ((i + cur) % 2 == 1) {
      if (a[i] > x) {
        cnt++;
        cur = 1 - cur;
      }
    }
  }
  if (cnt <= n - k) {
    return 1;
  }
  cnt = 0;
  cur = 0;
  for (int i = 1; i <= n; i++) {
    if ((i + cur) % 2 == 0) {
      if (a[i] > x) {
        cnt++;
        cur = 1 - cur;
      }
    }
  }
  if (cnt <= n - k) {
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 1, r = 1e9;
  while (l != r) {
    if (l + 1 == r) {
      if (!check(l)) {
        l = r;
      }
      break;
    }
    int m = (l + r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n"; 
  // cout << check(1) << "\n";
}