#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto ask = [](int q) -> int {
    cout << "? " << q << endl;
    int ans;
    cin >> ans;
    return ans;
  };
  int n;
  cin >> n;
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    int m_v = ask(m);
    int l_v = INF, r_v = INF;
    if (m != l) {
      l_v = ask(m - 1);
    }
    if (m != r) {
      r_v = ask(m + 1);
    }
    if (l_v > m_v && r_v > m_v) {
      cout << "! " << m << endl;
      return 0;
    }
    if (l_v > m_v) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << "! " << l << endl;
}
