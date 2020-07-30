#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

string s, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> t;
  if (sz(s) != sz(t)) {
    cout << max(sz(s), sz(t)) << "\n";
  } else {
    if (s != t) {
      cout << sz(s) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}