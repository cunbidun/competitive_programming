/**
 *  author: cunbidun
 *  created: Tuesday, 2023-01-24 18:09:51 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M, K;
    cin >> N >> M >> K;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
      if (s[i] != s[i + 1]) {
        i++;
        ans++;
      }
    }
    if (K < ans) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}
