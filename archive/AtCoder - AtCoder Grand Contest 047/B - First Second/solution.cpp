/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-19 17:50:08 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct trie {
  int current_id;
  vector<vector<int>> _trie, _sum;
  trie() {
    current_id = 0;
    _trie.assign((int)1e6 + 10, vector<int>(26, -1));
    _sum.assign((int)1e6 + 10, vector<int>(26, 0));
  }
  void add(string &s) {
    int id = 0;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < (int)s.size(); i++) {
      if (_trie[id][s[i] - 'a'] == -1) {
        _trie[id][s[i] - 'a'] = ++current_id;
      }
      id = _trie[id][s[i] - 'a'];
      st.push(id);
    }
    int index = s.size() - 1;
    vector<int> buffer(26);
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (int j = 0; j < 26; j++) {
        _sum[u][j] += buffer[j];
      }
      if (index >= 0) {
        buffer[s[index] - 'a'] = 1;
        index--;
      }
    }
  }

  int get(string &s) {
    int id = 0;
    for (int i = 0; i < (int)s.size() - 1; i++) {
      id = _trie[id][s[i] - 'a'];
      if (id == -1) {
        return 0;
      }
    }
    return _sum[id][s.back() - 'a'];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<string> S(N);
  trie t;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    reverse(S[i].begin(), S[i].end());
  }

  sort(S.begin(), S.end(), [](auto f, auto s) { return f.size() > s.size(); });
  for (int i = 0; i < N; i++) {
    ans += t.get(S[i]);
    t.add(S[i]);
  }
  cout << ans << '\n';
}
