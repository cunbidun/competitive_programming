#include <bits/stdc++.h>

using namespace std;

class DistinctStrings {
public:
  vector<string> generate(int L, string letters, int N) {
    mt19937 rng(99);
    set<string> s;
    int l = (int)letters.size();
    while ((int)s.size() < N) {
      string tmp;
      for (int i = 0; i < L; i++) {
        tmp += letters[rng() % l];
      }
      s.insert(tmp);
    }
    return vector<string>(s.begin(), s.end());
  }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
