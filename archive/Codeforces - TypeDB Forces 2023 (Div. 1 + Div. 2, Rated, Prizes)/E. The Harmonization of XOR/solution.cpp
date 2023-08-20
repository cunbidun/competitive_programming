/**
 *  author: cunbidun
 *  created: Wednesday, 2023-07-26 23:31:55 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, K, X;
    cin >> N >> K >> X;
    int most_sig = 31 - __builtin_clz(X);
    int sum = 0;
    for (int i = 1; i <= N; i++) {
      sum ^= i;
    }
    if (K % 2 == 0 && sum != 0) {
      cout << "NO" << '\n';
      continue;
    }
    if (K % 2 == 1 && sum != X) {
      cout << "NO" << '\n';
      continue;
    }
    vector<vector<int>> part;
    vector<int> used(N + 1);
    for (int i = 1; i <= N; i++) {
      if ((i >> most_sig) & 1) {
        vector<int> a;
        a.push_back(i);
        if ((X ^ i) != 0) {
          a.push_back(X ^ i);
        }
        for (auto j : a) {
          used[j] = 1;
        }
        part.push_back(a);
      }
    }

    vector<int> tmp;
    for (int i = 1; i <= N; i++) {
      if (!used[i]) {
        tmp.push_back(i);
      }
    }
    if (!tmp.empty()) {
      part.push_back(tmp);
    }
    if ((int)part.size() < K) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < K - 1; i++) {
      cout << part[i].size() << ' ';
      for (int j : part[i]) {
        cout << j << ' ';
      }
      cout << '\n';
    }

    // last part
    tmp.clear();
    for (int i = K - 1; i < (int)part.size(); i++) {
      for (int j : part[i]) {
        tmp.push_back(j);
      }
    }
    cout << tmp.size() << ' ';
    for (int j : tmp) {
      cout << j << ' ';
    }
    cout << '\n';
  }
}
