#include <bits/stdc++.h>

using namespace std;

// Code below this line will be copied.

const int N = 3e5 + 5;
const int INF = 1e9 + 5;
 
int n, a[N], f[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i] = N;
    cin >> a[i];
  }
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] == a[i]) {
      f[i] = f[i - 1] + 1;
    }
    if (a[i - 1] > a[i]) {
      int cur = INF;
      for (int j = i - 1; j >= 1; j--) {
        if (a[j] < cur) {
          f[i] = min(f[i], f[j] + 1);
          cur = a[j];
          if (cur <= a[i]) {
            break;
          }
        }
      }
    }
    if (a[i - 1] < a[i]) {
      int cur = 0;
      for (int j = i - 1; j >= 1; j--) {
        // cout << j << "\n";
        if (a[j] > cur) {
          f[i] = min(f[i], f[j] + 1);
          cur = a[j];
          if (cur >= a[i]) {
            break;
          }
        }
      }
    }
  }
  cout << f[n] << "\n";
  return 0;
}