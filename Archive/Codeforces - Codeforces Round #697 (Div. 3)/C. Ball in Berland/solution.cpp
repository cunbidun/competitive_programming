#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int a, b, k, A[N], B[N];

void solve() {
  cin >> a >> b >> k;
  for (int i = 1; i <= max(a, b); i++) {
    A[i] = B[i] = 0;
  }
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    A[x]++;
  }
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    B[x]++;
  }
  ll tot = 1LL * k * (k - 1) / 2;
  for (int i = 1; i <= a; i++) {
    tot -= 1LL * A[i] * (A[i] - 1) / 2;
  }
  for (int i = 1; i <= b; i++) {
    tot -= 1LL * B[i] * (B[i] - 1) / 2;
  }
  cout << tot << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
