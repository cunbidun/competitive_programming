#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  ll s1 = 0, s2 = 0, s3 = 0;
  vector<ii> l;
  for (int i = 1; i <= n1; i++) {
    int x;
    cin >> x;
    l.push_back({x, 1});
    s1 += x;
  }
  for (int i = 1; i <= n2; i++) {
    int x;
    cin >> x;
    l.push_back({x, 2});
    s2 += x;
  }
  for (int i = 1; i <= n3; i++) {
    int x;
    cin >> x;
    l.push_back({x, 3});
    s3 += x;
  }
  ll s = s1 + s2 + s3;
  sort(all(l));
  int mn = l[0].first, p = l[0].second, nx = -1;
  for (int i = 0; i < sz(l); i++) {
    if (l[i].second != p) {
      nx = l[i].first;
      break;
    }
  }
  cout << max((s - 2 * min(min(s1, s2), s3)), s - 2 * (mn + nx)) << "\n";
}
