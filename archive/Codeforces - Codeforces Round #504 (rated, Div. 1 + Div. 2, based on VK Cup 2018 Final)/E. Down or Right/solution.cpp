#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  auto ask = [&](int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    string res;
    cin >> res;
    return res[0] == 'Y';
  };
  int x = n, y = n;
  vector<ii> l1, l2;
  l1.push_back({n, n});
  l2.push_back({1, 1});
  while (x - 1 + y - 1 - 1 >= n - 1) {
    if (x > 1 && ask(1, 1, x - 1, y)) {
      l1.push_back({x - 1, y});
      x--;
    } else {
      l1.push_back({x, y - 1});
      y--;
    }
  }
  x = 1, y = 1;
  while (n - x + n - y - 1 >= n - 1) {
    if (y < n && ask(x, y + 1, n, n)) {
      l2.push_back({x, y + 1});
      y++;
    } else {
      l2.push_back({x + 1, y});
      x++;
    }
  }
  reverse(all(l1));
  for (int i = 1; i < sz(l1); i++) {
    l2.push_back(l1[i]);
  }
  cout << "! ";
  for (int i = 1; i < sz(l2); i++) {
    if (l2[i].first != l2[i - 1].first) {
      cout << "D";
    } else {
      cout << "R";
    }
  }
  cout << endl;
}
