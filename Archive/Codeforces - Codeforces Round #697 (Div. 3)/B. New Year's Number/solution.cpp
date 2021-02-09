#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e6 + 5;
int f[N];

void solve() {
  ll n;
  cin >> n;
  if (!f[n]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  f[0] = 1;
  f[2020] = 1;
  f[2021] = 1;
  for (int i = 2022; i <= N - 5; i++) {
    f[i] = f[i - 2020] || f[i - 2021];
  }
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
