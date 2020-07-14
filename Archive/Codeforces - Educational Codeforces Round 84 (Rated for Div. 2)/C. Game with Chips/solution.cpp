#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m, k;
vector<char> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n - 1; i++) {
    ans.push_back('U');
  }
  for (int i = 1; i <= m - 1; i++) {
    ans.push_back('L');
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) {
      if (i % 2 == 1) {
        ans.push_back('R');
      } else {
        ans.push_back('L');
      }
    }
    if (i != n) {
      ans.push_back('D');
    }
  }
  cout << sz(ans) << '\n';
  for (char c : ans) {
    cout << c;
  }
  cout << "\n";
}