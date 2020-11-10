#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  d += a / 2;
  a %= 2;
  if (d > 1) {
    d = 1;
  }
  c += b / 2;
  b %= 2;
  if (c > 1) {
    c = 1;
  }

  if (a == 1 && d == 1) {
    d = 0;
  }
  if (b == 1 && c == 1) {
    c = 0;
  }
  // cout << a << " " << b << " " << c << " " << d << "\n";
  if (a == 1 && b == 1) {
    cout << "Tidak Tidak Ya Ya\n";
    return;
  }
  if (a == 1 && c == 1) {
    cout << "Ya Ya Tidak Tidak\n";
    return;
  }

  if (b == 1 && d == 1) {
    cout << "Ya Ya Tidak Tidak\n";
    return;
  }

  if (c == 1 && d == 1) {
    cout << "Tidak Tidak Ya Ya\n";
    return;
  }

  if (a == 1) {
    cout << "Ya Tidak Tidak Tidak\n";
    return;
  }

  if (b == 1) {
    cout << "Tidak Ya Tidak Tidak\n";
    return;
  }

  if (c == 1) {
    cout << "Tidak Tidak Ya Tidak\n";
    return;
  }

  if (d == 1) {
    cout << "Tidak Tidak Tidak Ya\n";
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}