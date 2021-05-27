#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[55];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vi> ans;
  while (1) {
    bool ch = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        ch = 1;
        int p;
        for (int j = i + 1; j <= n; j++) {
          if (a[j] == a[i] - 1) {
            p = j;
            break;
          }
        }
        int q = p;
        while (p > 0) {
          if (a[p - 1] == a[p] - 1) {
            p--;
          } else {
            break;
          }
        }
        vi res;
        // cout << i << " " << p << " " << q << "\n";
        if (i > 1) {
          res.push_back(i - 1);
        }
        res.push_back(p - i);
        res.push_back(q - p + 1);
        if (q < n) {
          res.push_back(n - q);
        }
        ans.push_back(res);
        vi l1, l2, l3, l4;
        for (int j = 1; j < i; j++) {
          l1.push_back(a[j]);
        }
        for (int j = i; j < p; j++) {
          l2.push_back(a[j]);
        }
        for (int j = p; j <= q; j++) {
          l3.push_back(a[j]);
        }
        for (int j = q + 1; j <= n; j++) {
          l4.push_back(a[j]);
        }
        int cur = 1;
        for (int j : l4) {
          a[cur++] = j;
        }
        for (int j : l3) {
          a[cur++] = j;
        }
        for (int j : l2) {
          a[cur++] = j;
        }
        for (int j : l1) {
          a[cur++] = j;
        }
        // for (int i = 1; i <= n; i++) {
        //   cout << a[i] << " ";
        // }
        // cout << "\n";
        break;
      }
    }
    if (!ch) {
      break;
    }
  }
  cout << sz(ans) << "\n";
  for (vi res : ans) {
    cout << sz(res) << " ";
    for (int i : res) {
      cout << i << " ";
    }
    cout << "\n";
  }
}