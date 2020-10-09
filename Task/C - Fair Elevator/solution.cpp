#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e3 + 5;

int n, a[N], b[N], f[2 * N];
set<int> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    f[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] != -1 && s.find(a[i]) != s.end()) {
      cout << "No\n";
      return 0;
    } else {
      s.insert(a[i]);
    }
    if (b[i] != -1 && s.find(b[i]) != s.end()) {
      cout << "No\n";
      return 0;
    } else {
      s.insert(b[i]);
    }
    if (a[i] != -1 && b[i] != -1) {
      if (b[i] <= a[i]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  s.clear();
  for (int i = 1; i <= 2 * n; i++) {
    s.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1 && b[i] != -1) {
      for (int j = a[i]; j <= b[i]; j++) {
        if (f[j] != -1 && f[j] != b[i] - a[i] - 1) {
          cout << "No\n";
          return 0;
        }
        if (f[j] == -1) {
          f[j] = b[i] - a[i] - 1;
        }
      }
      s.erase(a[i]);
      s.erase(b[i]);
    }
  }

  while (1) {
    int ch = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != -1 && b[i] == -1 && f[a[i]] != -1) {
        s.erase(a[i]);
        s.erase(a[i] + f[a[i]] + 1);
        for (int j = a[i]; j <= a[i] + f[a[i]] + 1; j++) {
          if (f[j] != -1 && f[j] != f[a[i]]) {
            cout << "No\n";
            return 0;
          }
          if (f[j] == -1) {
            f[j] = f[a[i]];
            ch = 1;
          }
        }
      }
      if (a[i] == -1 && b[i] != -1 && f[b[i]] != -1) {
        s.erase(b[i]);
        s.erase(b[i] - f[b[i]] - 1);
        for (int j = b[i] - f[b[i]] - 1; j <= b[i]; j++) {
          if (f[j] != -1 && f[j] != f[b[i]]) {
            cout << "No\n";
            return 0;
          }
          if (f[j] == -1) {
            f[j] = f[b[i]];
            ch = 1;
          }
        }
      }
    }
    if (ch == 0) {
      break;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] != -1 && b[i] == -1 && f[a[i]] == -1) {
      if (f[a[i] + 1] != -1) {
        cout << "No\n";
        return 0;
      }
      f[a[i]] = 0;
      f[a[i] + 1] = 0;
      s.erase(a[i]);
      s.erase(a[i] + 1);
    }
    if (a[i] == -1 && b[i] != -1 && f[b[i]] == -1) {
      if (f[b[i] - 1] != -1) {
        cout << "No\n";
        return 0;
      }
      f[b[i]] = 0;
      f[b[i] - 1] = 0;
      s.erase(b[i]);
      s.erase(b[i] - 1);
    }
  }
  set<int> t;
  vi l;

  for (int i : s) {
    t.insert(i);
    l.push_back(i);
  }
  // for (int i = 1; i <= 2 * n; i++) {
  //   cout << f[i] << " ";
  // }
  // cout << "\n";
  // for (int i : s) {
  //   cout << i << " ";
  // }
  // cout << "\n";

  for (int ii = 0; ii < sz(l); ii++) {
    int i = l[ii];
    if (f[i] != -1) {
      continue;
    }
    int ch = 0;
    if (sz(t) == 0) {
      break;
    }
    for (int jj = sz(l) - 1; jj >= 0; jj--) {
      int j = l[jj];
      if (t.find(i) != t.end() && t.find(j) != t.end()) {
        int ff = 0;
        for (int l = min(i, j); l <= max(i, j); l++) {
          if (f[l] != -1 && f[l] != max(i, j) - min(i, j) - 1) {
            // cout << i << " " << j << " " << l << " " << f[l] << "\n";
            ff = 1;
            break;
          }
        }
        if (!ff) {
          t.erase(i);
          t.erase(j);
          for (int l = min(i, j); l <= max(i, j); l++) {
            f[l] = max(i, j) - min(i, j) - 1;
          }
          ch = 1;
          break;
        }
      }
    }
    if (ch == 0) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
}