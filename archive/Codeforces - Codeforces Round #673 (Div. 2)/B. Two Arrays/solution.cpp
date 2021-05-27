#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int b[N];

void solve() {
  int n, T, cnt = 0;
  set<int> s;
  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] * 2 == T) {
      cnt++;
    }
  }
  cnt /= 2;
  for (int i = 1; i <= n; i++) {
    if (b[i] * 2 < T) {
      cout << 1 << " ";
    } else if (b[i] * 2 == T) {
      if (cnt > 0) {
        cout << 1 << " ";
        cnt--;
      } else {
        cout << 0 << " ";
      }
    } else {
      cout << 0 << " ";
    }
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