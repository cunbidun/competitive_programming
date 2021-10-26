#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B ,C;
  cin >> A >> B>> C;
  for (int i = A; i <=B; i++) {
    if (i %C == 0) {
      cout << i<< '\n';
      return 0;
    }
  }
  cout << "-1\n";
}
