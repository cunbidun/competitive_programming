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

// Code below this line will be copied.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = (a[i] < k ? -1 : (a[i] > k ? 1 : 0));
      zeros += (a[i] == 0);
    }
    if (zeros == 0) {
      cout << "no" << '\n';
      continue;
    }
    if (zeros == n) {
      cout << "yes" << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      ok |= (a[i] >= 0 && a[i + 1] >= 0);
    }
    for (int i = 0; i < n - 2; i++) {
      ok |= (a[i] >= 0 && a[i + 2] >= 0);
    }
    cout << (ok ? "yes" : "no") << '\n';
  }
  return 0;
}