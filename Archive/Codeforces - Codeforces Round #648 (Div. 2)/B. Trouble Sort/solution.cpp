#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int a[501];
int n;
int solve() {
  cin >> n;
  int cnt = 0;
  int ch = 1;
  rf(i, 1, n) {
    cin >> a[i];
    if (a[i] < a[i - 1]) ch = 0;
  }
  rf(i, 1, n) {
    int x;
    cin >> x;
    cnt += x;
  }
  if (cnt < n && cnt > 0) return cout << "Yes\n", 0;
  if (ch) return cout << "Yes\n", 0;
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}