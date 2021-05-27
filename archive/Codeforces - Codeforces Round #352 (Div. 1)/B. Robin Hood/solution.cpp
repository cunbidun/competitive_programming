#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5e5 + 5;

int n, k, a[N];
ll s[N];

int check_min(int mn) {
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (a[m] > mn) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int p = r - 1;
  return 1LL * p * mn - s[p] <= k;
}

int check_max(int mx) {
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (a[m] < mx) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  int p = r + 1;
  return (s[n] - s[p - 1]) - 1LL * (n - p + 1) * mx <= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }
  int l = a[1];
  int r = s[n] / n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check_min(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  int mn = r;

  l = (s[n] + n - 1) / n;
  r = a[n];
  while (l < r) {
    int m = (l + r) / 2;
    if (check_max(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int mx = r;
  
  cout << mx - mn << "\n";
}