#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
string organizingContainers(vector<vector<int>> M) {
  int n = M.size();
  int cr[n];
  int cc[n];

  for (int i = 0; i < n; i++) {
    cc[i] = 0;
    cr[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cr[i] += M[i][j];
      cc[j] += M[i][j];
    }
  }

  sort(cr, cr + n);
  sort(cc, cc + n);

  for (int i = 0; i < n; i++) {
    if (cr[i] != cc[i]) {
      return "Impossible";
    }
  }
  return "Possible";
}

int main() {
  int q;
  cin >> q;
  string answer = "";
  for (int a0 = 0; a0 < q; a0++) {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));
    for (int M_i = 0; M_i < n; M_i++) {
      for (int M_j = 0; M_j < n; M_j++) {
        cin >> M[M_i][M_j];
      }
    }

    string result = organizingContainers(M);
    if (answer == "") {
      answer = result;
    } else {
      answer = answer + "," + result;
    }
  }

  // Do not remove below line
  cout << answer << endl;
  // Do not print anything after this line

  return 0;
}