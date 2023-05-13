How I solve this problem?

1. For each new road `u` to `v` that has weight `w`, find the shortage path from every other node to `u` and `v`. Then use that information to calculate new shortage distance between all pairs (we try to move from `i` to `j` using the newly added edge).

2. However, the shortest distance between every node to `u` and `v` are already given (the matrix itself), so we just need to use it without any recalculations.

```
 for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      m[i][j] = min(m[i][j], m[u][i] + w + m[v][j]);
      m[i][j] = min(m[i][j], m[u][j] + w + m[v][i]);
    }
  }
```                            
