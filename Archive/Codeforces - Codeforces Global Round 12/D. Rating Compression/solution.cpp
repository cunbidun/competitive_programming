#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 1;

int n, a[N], cnt[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] != 1) {
      ok = 0;
    }
  }
  vi v;
  int l = 1, r = n;
  for (int i = 1; i < n; i++) {
    if (cnt[i] == 0) {
      for (int j = i; j < n; j++) {
        v.push_back(0);
      }
      break;
    } else {
      v.push_back(1);
      if (cnt[i] > 1) {
        for (int j = i + 1; j < n; j++) {
          v.push_back(0);
        }
        break;
      }
      if (a[l] == i) {
        l++;
      } else if (a[r] == i) {
        r--;
      } else {
        for (int j = i + 1; j < n; j++) {
          v.push_back(0);
        }
        break;
      }
    }
  }
  v.push_back(ok);
  reverse(all(v));
  for (int i : v) {
    cout << i;
  }
  cout << "\n";
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
