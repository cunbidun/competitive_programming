#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[1001];

int find_mex() {
  int ch[1001];
  for (int i = 0; i <= n; i++) {
    ch[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    ch[a[i]] = 1;
  }
  int mex = 0;
  while (ch[mex]) {
    mex++;
  }
  return mex;
}

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vi ans;
  for (int i = 1; i <= n; i++) {
    while (a[i] != i - 1) {
      int mex = find_mex();
      if (mex > n - 1) {
        a[i] = mex;
        ans.push_back(i);
      } else {
        a[mex + 1] = mex;
        ans.push_back(mex + 1);
      }
    }
  }

  cout << sz(ans) << "\n";
  for (int i : ans) {
    cout << i << " ";
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