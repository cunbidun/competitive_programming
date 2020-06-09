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

int an, am, bn, bm;
char a[51][51], b[51][51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> an >> am;
  rf(i, 1, an) rf(j, 1, am) cin >> a[i][j];
  cin >> bn >> bm;
  rf(i, 1, bn) rf(j, 1, bm) cin >> b[i][j];
  int ans = 0;
  int X = 0, Y = 0;
  rf(x, -50, 50) rf(y, -50, 50) {
    int cur = 0;
    rf(i, 1, an) rf(j, 1, am) {
      if (x + i < 1 || y + j < 1 || x + i > bn || y + j > bm) continue;
      cur += (a[i][j] - '0') * (b[x + i][y + j] - '0');
    }
    if (ans < cur) {
      ans = cur;
      X = x;
      Y = y;
    }
  }
  cout << X << " " << Y << "\n";
}