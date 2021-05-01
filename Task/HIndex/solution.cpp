#include <bits/stdc++.h>

using namespace std;

class HIndex {
public:
  int cheat(vector<int> realCitations, int budget, int citationPrice) {
    sort(realCitations.begin(), realCitations.end());
    reverse(realCitations.begin(), realCitations.end());
    int n = realCitations.size();
    int l = 0, r = n;
    while (l < r) {
      int m = (l + r + 1) / 2;
      long long res = 0;
      for (int i = 0; i < m; i++) {
        res += max(m - realCitations[i], 0);
      }
      if (res * citationPrice <= budget) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    return l;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  HIndex m;
  m.cheat({25, 3, 5, 3, 8, 0}, 1001, 1000);
}
