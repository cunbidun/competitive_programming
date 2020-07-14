#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 1;
int n, p;
int a[N], b[N], cnt[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j] <= i) {
        cnt[i] = j;
      } else {
        break;
      }
    }
    if (i >= a[n])
      cnt[i] = n;
  }
  vi ans;
  for (int x = 1; x <= 2000; x++) {
    int res = 1;
    for (int i = 0; i < n; i++) {
      res = (res * (cnt[min(x + i, 2000)] - i)) % p;
    }
    if (res != 0)
      ans.push_back(x);
  }

  cout << sz(ans) << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << '\n';
}