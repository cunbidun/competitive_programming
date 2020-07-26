package Code;

import Lib.Algorithm.MaxMin;

@SuppressWarnings("unused")
public class CageTheMonster {
    private int n, m;
    private boolean reachBorder;
    private String[] labyrinth;
    private boolean[][] vis;

    public int capture(String[] labyrinth) {
        this.labyrinth = labyrinth;
        n = labyrinth.length;
        m = labyrinth[0].length();
        int ans = 4;
        boolean hasPos = false;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++)
                if (labyrinth[i].charAt(j) == '^') {
                    hasPos = true;
                    if (!check(i, j, -1, n, -1, m)) return 0;

                    if (!check(i, j, i - 1, n, -1, m)) ans = MaxMin.Min(ans, 1);

                    if (!check(i, j, -1, i + 1, -1, m)) ans = MaxMin.Min(ans, 1);

                    if (!check(i, j, -1, n, j - 1, m)) ans = MaxMin.Min(ans, 1);

                    if (!check(i, j, -1, n, -1, j + 1)) ans = MaxMin.Min(ans, 1);

                    if (!check(i, j, i - 1, i + 1, -1, m)) ans = MaxMin.Min(ans, 2);

                    if (!check(i, j, -1, n, j - 1, j + 1)) ans = MaxMin.Min(ans, 2);

                    if (!check(i, j, i - 1, n, j - 1, m)) ans = MaxMin.Min(ans, 2);

                    if (!check(i, j, i - 1, n, -1, j + 1)) ans = MaxMin.Min(ans, 2);

                    if (!check(i, j, -1, i + 1, j - 1, m)) ans = MaxMin.Min(ans, 2);

                    if (!check(i, j, -1, i + 1, -1, j + 1)) ans = MaxMin.Min(ans, 2);
                }
        }
        if (!hasPos) return -1;

        if (ans != 4) return ans;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++)
                if (labyrinth[i].charAt(j) == '^') {
                    for (int k = i - 1; k >= 0; k--) if (labyrinth[k].charAt(j) == '#') return 3;
                    for (int k = i + 1; k < n; k++) if (labyrinth[k].charAt(j) == '#') return 3;
                    for (int k = j - 1; k >= 0; k--) if (labyrinth[i].charAt(k) == '#') return 3;
                    for (int k = j + 1; k < m; k++) if (labyrinth[i].charAt(k) == '#') return 3;
                }
        }
        return 4;
    }

    private boolean check(int i, int j, int U, int D, int L, int R) {
        vis = new boolean[n][m];
        reachBorder = false;
        dfs(i, j, U, D, L, R);
        return reachBorder;

    }

    private void dfs(int i, int j, int U, int D, int L, int R) {
        if (i == U || i == D) return;
        if (j == L || j == R) return;
        if (labyrinth[i].charAt(j) == '#') return;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            reachBorder = true;
            return;
        }

        vis[i][j] = true;
        if (!vis[i + 1][j] && labyrinth[i + 1].charAt(j) != '#')
            dfs(i + 1, j, U, D, L, R);
        if (!vis[i - 1][j] && labyrinth[i - 1].charAt(j) != '#')
            dfs(i - 1, j, U, D, L, R);
        if (!vis[i][j + 1] && labyrinth[i].charAt(j + 1) != '#')
            dfs(i, j + 1, U, D, L, R);
        if (!vis[i][j - 1] && labyrinth[i].charAt(j - 1) != '#')
            dfs(i, j - 1, U, D, L, R);


    }
}