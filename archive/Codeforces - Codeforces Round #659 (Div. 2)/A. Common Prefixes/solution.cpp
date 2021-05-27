#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  int n;
  cin >> n;
  string s = "";
  for (int i = 1; i <= 100; i++) {
    s += 'a';
  }
  cout << s << "\n";
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    string t = "";
    for (int i = 0; i < x; i++) {
      t += s[i];
    }
    if (s[x] == 'a') {
      t += 'b';
    } else {
      t += 'a';
    }
    while (sz(t) <= 100) {
      t += "z";
    }

    cout << t << "\n";
    s = t;
  }
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