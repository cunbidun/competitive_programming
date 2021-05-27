#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[200005];
int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int st = 0, en = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      st = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != i) {
      en = i;
      break;
    }
  }
  if (st == 0) {
    cout << 0 << "\n";
    return 0;
  }
	int ch = 0;
  for (int i = st; i <= en; i++) {
		if(a[i] == i) {
			ch = 1;
			break;
		} 
	}
	cout << 1 + ch << "\n";
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