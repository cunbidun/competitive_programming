#include <bits/stdc++.h>

using namespace std;

class Pancakes {
public:
  vector<string> makePancakes(int N, int P) {
    queue<char> q;
    for (char i = 'a'; i <= (char)('a' + N - 1); i++) {
      q.push(i);
    }
    for (char i = 'A'; i <= (char)('A' + N - 1); i++) {
      q.push(i);
    }

    string p = "";
    vector<string> ans;
    while (!q.empty()) {
      if (p.size() == P) {
        ans.push_back(p);
        p = "";
      }
      int f = 0;
      for (int i = 0; i < p.size(); i++) {
        if (q.front() == (char)(p[i] - 32)) {
          f = 1;
          break;
        }
      }
      if (f) {
        while (p.size() < P) {
          p += '-';
        }
        ans.push_back(p);
        p = "";
      }
      p += q.front();
      q.pop();
    }

    while (p.size() < P) {
      p += '-';
    }
    ans.push_back(p);
    // for (string s : ans) {
    //   cout << s << '\n';
    // }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Pancakes m;
  // m.makePancakes(5, 4);
  m.makePancakes(1, 5);
  m.makePancakes(10, 15);
}
