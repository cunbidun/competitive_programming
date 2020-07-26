#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int l = 1, r = n;
  while (m--) {
    string a, dir;
    int num;
    cin >> a >> a >> dir >> a >> num;
    if (dir == "right") {
      l = max(l, num + 1);
    }
    if (dir == "left") {
      r = min(r, num - 1);
    }
  }
  if (l > r) {
    cout << "-1\n";
    return 0;
  }
  cout << r - l + 1 << '\n';
}