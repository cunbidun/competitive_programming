#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

double pi = 3.14159265358;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int w, l, k;
  cin >> k >> w >> l;
  int cnt = 1;
  for (int i = 2; i <= k; i++) {
    cnt += (1 << i);
  }
  cnt += (1 << k);
  double x = 1.0 * l / cnt;
  double h = 1.0 * w / 2;
  cout << atan(x / h) * 180 / pi << '\n';
}
