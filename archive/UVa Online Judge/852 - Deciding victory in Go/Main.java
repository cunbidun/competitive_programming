package Code;

import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class DecidingVictoryInGo {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private InputReader in;
    private PrintWriter out;
    private char[][] a;
    private boolean[][] vis;
    private boolean black, white;
    private int cnt;
    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {-1, 1, 0, 0};

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
        int t = in.nextInt();
        while (t-- > 0) {
            vis = new boolean[10][10];
            int ansB = 0;
            int ansW = 0;
            a = in.nextCharTable(9, 9, 1, 1);
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; j++) {
                    if (a[i][j] == 'X') ansB++;
                    else if (a[i][j] == 'O') ansW++;
                    else if (!vis[i][j]) {
                        cnt = 0;
                        black = false;
                        white = false;
                        dfs(i, j);
                        if (black && white) continue;
                        if (black) ansB += cnt;
                        if (white) ansW += cnt;
                    }
                }
            }
            out.println("Black " + ansB + " White " + ansW);
        }
    }

    private void dfs(int i, int j) {
        if (a[i][j] == 'X') {
            black = true;
            return;
        }
        if (a[i][j] == 'O') {
            white = true;
            return;
        }
        vis[i][j] = true;
        cnt++;
        for (int k = 0; k <= 3; k++) {
            if (inSide(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]])
                dfs(i + dx[k], j + dy[k]);
        }
    }

    private boolean inSide(int i, int j) {
        return i <= 9 && i >= 1 && j <= 9 && j >= 1;
    }

}
