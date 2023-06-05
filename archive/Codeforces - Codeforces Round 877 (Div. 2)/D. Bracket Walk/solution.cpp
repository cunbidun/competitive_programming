/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-04 10:50:27 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  set<int> s;
  for (int i = 0; i < N; i++) {
    char x;
    cin >> x;
    if (i % 2 == 0 && x == ')') {
      s.insert(i);
    }
    if (i % 2 == 1 && x == '(') {
      s.insert(i);
    }
  }
  while (Q--) {
    int p;
    cin >> p;
    p--;
    if (N % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (s.find(p) != s.end()) {
      s.erase(p);
    } else {
      s.insert(p);
    }
    if (!s.empty() && (*s.begin() % 2 == 0 || *s.rbegin() % 2 == 1)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
};
