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
int a[N][4];
int c[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  rf(i, 1, m) cin >> a[i][1] >> a[i][2] >> a[i][3];
  rf(i, 1, m) {
    int x = a[i][1];
    int y = a[i][2];
    int z = a[i][3];
    if (c[x] == c[y] && c[y] == c[z] && c[x] == 0) {
      c[x] = 1;
      c[y] = 2;
      c[z] = 3;
    } else {
      if (c[x] != 0) {
        int cur = 7 - (1 << (c[x] - 1));
        c[y] = __builtin_ffs(cur);
        cur -= (1 << (c[y] - 1));
        c[z] = __builtin_ffs(cur);
      } else if (c[y] != 0) {
        int cur = 7 - (1 << (c[y] - 1));
        c[x] = __builtin_ffs(cur);
        cur -= (1 << (c[x] - 1));
        c[z] = __builtin_ffs(cur);
      } else if (c[z] != 0) {
        int cur = 7 - (1 << (c[z] - 1));
        c[x] = __builtin_ffs(cur);
        cur -= (1 << (c[x] - 1));
        c[y] = __builtin_ffs(cur);
      }
    }
  }
  rf(i, 1, n) cout << c[i] << " ";
  cout << "\n";
}