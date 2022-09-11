#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  long long K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < K; i++) {
    for (int j = 0; j < N; j++) {
      a.push_back(a[j]);
    }
  }
  vector<int> ans;
  set<int> s;
  for (int i = 0; i < (int)a.size(); i++) {
    if (s.find(a[i]) == s.end()) {
      s.insert(a[i]);
      ans.push_back(a[i]);
    } else {
      while (s.find(a[i]) != s.end()) {
        s.erase(ans.back());
        ans.pop_back();
      }
    }
  }
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
