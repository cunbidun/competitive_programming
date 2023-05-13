# Pishty and Birthday
Problem Link: https://www.codechef.com/problems/PSHTBRTH

Read this first: https://codeforces.com/blog/entry/66040

1. Calculate the Grundy number for each matrix, there are only `2^16` of them in total.
```
// Because each matrix only contains 1 and 0, so we can present them as a number
int process(int num) {
  int a[5][5], s[5][5];
  for (int i = 0; i < 16; i++) {
    a[i / 4 + 1][i % 4 + 1] = ((num >> i) & 1);
  }
  // For quicky check if all numbers in a rectangle are all 1 we use prefix sum 2d
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      s[i][j] = 0;
    }
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i][j] - s[i - 1][j - 1];
    }
  }
  
  int mex = 0;
  set<int> cur;
  // For each possible rectangle...
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = i; k <= 4; k++) {
        for (int l = j; l <= 4; l++) {
          // if it consists of only number 1
          if (s[k][l] + s[i - 1][j - 1] - s[i - 1][l] - s[k][j - 1] == (k - i + 1) * (l - j + 1)) {
            int nn = 0;
            int cnt = -1;
            for (int ii = 1; ii <= 4; ii++) {
              for (int jj = 1; jj <= 4; jj++) {
                cnt++;
                // Skip cell if it lies inside the rectangle or its value is 0
                if ((ii >= i && ii <= k && jj >= j && jj <= l) || a[ii][jj] == 0) {
                  continue;
                }
                nn += 1 << cnt;
              }
            }
            // We use memorization to quicky calculate the mex
            cur.insert(G[nn]);
            while (cur.find(mex) != cur.end()) {
              mex++;
            }
          }
        }
      }
    }
  }
  G[num] = mex;
}

// Initialize the value of G[0] (empty matrix) to 0
G[0] = 0;
for (int i = 1; i <= (1 << 16) - 1; i++) {
  process(i);
}
```
2. The problem reduce to solving 2 types of query:
  * Point update: change one element to other value
  * Range query: find the xor sum from `l` to `r`
3. If the value of a range query is greater than 0, `Pishty` wins the game. Otherwise, `Lotsy` wins.