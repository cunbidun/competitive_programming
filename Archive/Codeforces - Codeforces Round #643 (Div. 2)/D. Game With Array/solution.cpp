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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  if (s < 2 * n) return cout << "NO", 0;
  cout << "YES\n";
  rf(i, 1, n - 1) { cout << 2 << " "; }
  cout << s - 2 * (n - 1) << "\n";
  cout << 1 << "\n";
}