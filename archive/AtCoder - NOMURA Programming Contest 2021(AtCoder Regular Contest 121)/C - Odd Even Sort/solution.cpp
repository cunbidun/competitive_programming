/**
 *  author: cunbidun
 *  created: Sunday, 2022-12-11 11:52:44 CST
 *  done: Sunday, 2022-12-11 11:59:00 CST
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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<int> ans;
    ans.push_back(0);
    auto change = [&](int i, int tar) {
      if ((i - 1) % 2 != ((int)ans.size()) % 2) {
        if (i > tar + 1) {
          ans.push_back(i - 2);
          swap(a[i - 2], a[i - 1]);
          ans.push_back(i - 1);
          swap(a[i - 1], a[i]);
        } else if (i == N) {
          ans.push_back(i - 2);
          swap(a[i - 2], a[i - 1]);
          ans.push_back(i - 1);
          swap(a[i - 1], a[i]);
          ans.push_back(i - 2);
          swap(a[i - 2], a[i - 1]);
          ans.push_back(i - 1);
          swap(a[i - 1], a[i]);
          ans.push_back(i - 2);
          swap(a[i - 2], a[i - 1]);
        } else {
          ans.push_back(i);
          swap(a[i], a[i + 1]);
          ans.push_back(i - 1);
          swap(a[i - 1], a[i]);
          ans.push_back(i);
          swap(a[i], a[i + 1]);
          ans.push_back(i - 1);
          swap(a[i - 1], a[i]);
          ans.push_back(i);
          swap(a[i], a[i + 1]);
        }
      } else {
        ans.push_back(i - 1);
        swap(a[i - 1], a[i]);
      }
    };
    for (int i = 1; i <= N; i++) {
      int pos = -1;
      for (int j = i; j <= N; j++) {
        if (a[j] == i) {
          pos = j;
          break;
        }
      }
      if (pos == i) {
        continue;
      }
      for (int j = pos; j > i; j--) {
        change(j, i);
      }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < (int)ans.size(); i++) {
      if (ans[i] % 2 != i % 2) {
        cout << "ans[" << i << "] = " << ans[i] << endl;
        return 1;
      }
      cout << ans[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= N; i++) {
      if (a[i] != i) {
        cout << "a[" << i << "] = " << a[i] << endl;
        return 1;
      }
    }
    assert((int)ans.size() - 1 <= N * N);
  }
}
