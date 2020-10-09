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
 
  int a, b, c;
  int d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (c < f) {
    cout << 0 << "\n";
    return 0;
  }

  if (c == f && b < e) {
    cout << 0 << "\n";
    return 0;
  }

  if (c == f && b == e && a <= d) {
    cout << 0 << "\n";
    return 0;
  }

  if (c != f) {
    cout << 10000 << "\n";
  } else {
    if (b != e) {
      cout << (b - e) * 500 << "\n";
    } else {
      cout << (a - d) * 15 << "\n";
    }
  }
}