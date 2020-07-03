#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int solve() {
  string s;
  cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '0')
      cnt0++;
    else
      cnt1++;
  }
  if (min(cnt0, cnt1) % 2 == 1)
    cout << "DA\n";
  else
    cout << "NET\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}