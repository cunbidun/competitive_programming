#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> l;
    auto cal = [&]() {
      if (n % 2 == 1) {
        l.push_back(1);
        l.push_back(n / 2);
        l.push_back(n / 2);
      } else {
        if (n % 4 == 0) {
          l.push_back(n / 2);
          l.push_back(n / 4);
          l.push_back(n / 4);
        } else {
          l.push_back(n / 2 - 1);
          l.push_back(n / 2 - 1);
          l.push_back(2);
        }
      }
    };
    while (k > 3) {
      l.push_back(1);
      n--;
      k--;
    }
    cal();
    for (int i : l) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
