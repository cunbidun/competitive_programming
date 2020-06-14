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

int n;
int a[N];
int solve() {
  cin >> n;
  rf(i, 1, n) cin >> a[i];
  vi ans;
  ans.pb(a[1]);
  int cur = a[1];
  rf(i, 2, n) {
    while (i < n && ((cur < a[i] && a[i] < a[i + 1]) || (cur > a[i] && a[i] > a[i + 1]))) {
      i++;
    }
    ans.pb(a[i]);
    cur = a[i];
  }
  cout << sz(ans) << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}