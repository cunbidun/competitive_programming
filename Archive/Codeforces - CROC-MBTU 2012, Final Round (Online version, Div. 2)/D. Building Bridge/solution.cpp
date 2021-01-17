#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
struct e {
  int location, distance, idx;
} a[N], b[N];
int n, m, x, y;

int cmp(e A, e B) {
  return A.location < B.location;
}

double p(int w, int h) {
  return sqrt(1.0 * w * w + 1.0 * h * h);
}
double cal(int i, int j) {
  double d1 = p(x, a[i].location);
  double d2 = p(x - y, abs(a[i].location - b[j].location));
  return d1 + d2 + b[j].distance;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].location;
    a[i].idx = i;
  }
  sort(a + 1, a + 1 + n, cmp);

  for (int i = 1; i <= m; i++) {
    cin >> b[i].location;
    b[i].idx = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].distance;
  }
  sort(b + 1, b + 1 + m, cmp);
  int cur = 1;
  double mn = 1e9;
  ii ans;
  for (int i = 1; i <= m; i++) {
    double last = cal(cur, i);
    while (cur < n) {
      double new_dis = cal(cur + 1, i);
      if (new_dis < last) {
        last = new_dis;
        cur++;
      } else {
        break;
      }
    }
    if (last < mn) {
      mn = last;
      ans = {cur, i};
    }
  }
  cout << a[ans.first].idx << " " << b[ans.second].idx << "\n";
}
