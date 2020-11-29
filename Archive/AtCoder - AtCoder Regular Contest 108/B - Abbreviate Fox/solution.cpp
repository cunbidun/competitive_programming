#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vi l;
  cin >> n >> s;
  int ans = n;
  for (int i = 0; i < n; i++) {
    l.push_back(s[i]);
    if (sz(l) >= 3) {
      if (l[sz(l) - 1] == 'x' && l[sz(l) - 2] == 'o' && l[sz(l) - 3] == 'f') {
        l.pop_back();
        l.pop_back();
        l.pop_back();
        ans -= 3;
      }
    }
  }
  cout << ans << "\n";
}