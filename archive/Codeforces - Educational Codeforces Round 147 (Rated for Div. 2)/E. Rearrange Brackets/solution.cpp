/**
 *  author: cunbidun
 *  created: Saturday, 2023-07-22 15:10:52 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    string S;
    cin >> N;
    cin >> S;
    stack<int> stack;
    vector<int> a;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == '(') {
        stack.push(i);
      } else {
        auto top = stack.top();
        stack.pop();
        a.push_back((i - top - 1) / 2);
        // cout << top << ' ' << i << '\n';
      }
    }
    assert(stack.size() == 0);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long ans = 0;
    for (int i = N; i < (int)a.size(); i++) {
      ans += a[i];
    }
    cout << ans << '\n';
  }
}
