#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
ll a[26][26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i % 2 == 1) {
        a[i][j] = 0;
      } else {
        a[i][j] = 1LL << (i + j - 3);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    ll num;
    cin >> num;
    vector<pair<int, int>> path;
    int x = n, y = n;
    while (x != 1 && y != 1) {
      path.push_back({x, y});
      if (a[x][y] == 0) {
        if ((num & a[x - 1][y]) == a[x - 1][y]) {
          x--;
        } else {
          y--;
        }
      } else {
        if ((num & a[x][y - 1]) == a[x][y - 1]) {
          y--;
        } else {
          x--;
        }
      }
    }
    if (x == 1) {
      while (y != 0) {
        path.push_back({x, y--});
      }
    }

    if (y == 1) {
      while (x != 0) {
        path.push_back({x--, y});
      }
    }
    reverse(all(path));
    for (ii p : path) {
      cout << p.first << " " << p.second << endl;
    }
  }
}
