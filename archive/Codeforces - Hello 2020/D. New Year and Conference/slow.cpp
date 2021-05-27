#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  struct e {
    int i, sa, ea, sb, eb;
  };
  vector<e> E;
  for (int i = 0; i < N; i++) {
    int sa, ea, sb, eb;
    cin >> sa >> ea >> sb >> eb;
    E.push_back({i, sa, ea, sb, eb});
  }
  for (int i = 0; i < (int)E.size(); i++) {
    for (int j = 0; j < (int)E.size(); j++) {
      int a = max(E[i].sa, E[j].sa) <= min(E[i].ea, E[j].ea);
      int b = max(E[i].sb, E[j].sb) <= min(E[i].eb, E[j].eb);
      if ((a ^ b)) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
}
