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

int n, a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int cnt = 0;
  rf(i, 1, n) { cin >> a[i]; }
  int p = 0;
  rf(i, 1, n) {
    if (a[i] < a[i - 1]) {
      p = i;
      cnt++;
      if (cnt > 1) return cout << "-1\n", 0;
    }
  }
  if (p == 0)
    cout << 0 << "\n";
  else {
    if (a[n] > a[1])
      cout << "-1\n";
    else
      cout << n - p + 1 << "\n";
  }
}