#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a;
  for (int i = 0; i < N; i++) {
    char x;
    cin >> x;
    int num = 0;
    if (x == 'B') {
      num = 1;
    }
    if (x == 'R') {
      num = 2;
    }
    a.push_back(num);
  }
  for (int i = 1; i < N; i++) {
    vector<int> b;
    for (int j = 1; j < (int)a.size(); j++) {
      b.push_back((6 - a[j] - a[j - 1]) % 3);
    }
    a = b;
  }
  if (a[0] == 0) {
    cout << 'W' << '\n';
  }

  if (a[0] == 1) {
    cout << 'B' << '\n';
  }

  if (a[0] == 2) {
    cout << 'R' << '\n';
  }
}
