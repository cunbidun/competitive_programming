#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int cnt = 0;
  string ans = "";
  for (int i = 0; i < sz(s); i += 2) {
    if (s[i] != s[i + 1]) {
      ans += s[i];
      ans += s[i + 1];
    } else {
      ans += "ab";
      cnt++;
    }
  }
  cout << cnt << "\n";
  cout << ans << "\n";
}