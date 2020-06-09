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

int n, m;
int solve() {
  set<int> sr, sc;
  cin >> n >> m;
  rf(i, 1, n) rf(j, 1, m) {
    int x;
    cin >> x;
    if (x == 1) {
      sr.insert(i);
      sc.insert(j);
    }
  }
  int move = min(n - sz(sr), m - sz(sc));
  if (move % 2 == 0) return cout << "Vivek\n", 0;
  cout << "Ashish\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}