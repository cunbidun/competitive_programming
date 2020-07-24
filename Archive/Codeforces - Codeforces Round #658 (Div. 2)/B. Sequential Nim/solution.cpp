#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
int a[N];
int solve() {
  int n;
  cin >> n;
  int sum = 0;
  int p = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 1 && p == -1) {
      p = i;
    }
  }
  if (p == -1) {
    if (n % 2 == 1) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  } else {
    if (p % 2 == 1) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }
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