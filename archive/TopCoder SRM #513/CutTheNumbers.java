package Code;

import Lib.Algorithm.MaxMin;

@SuppressWarnings("unused")
public class CutTheNumbers {
    private int[][][][] f = new int[5][5][5][5];
    private int[][] a = new int[5][5];
    private int n;
    private int m;

    public int maximumSum(String[] board) {
        n = board.length;
        m = board[0].length();
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                for (int k = 1; k <= 4; k++)
                    for (int l = 1; l <= 4; l++)
                        f[i][j][k][l] = -1;

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length(); j++) {
                a[i + 1][j + 1] = (board[i].charAt(j) - '0');
            }
        }
        System.out.println(sol(1, 4, 4, 4) + sol(1, 1, 4, 3));
        return sol(1, 1, n, m);
    }


    private int sol(int i, int j, int k, int l) {
        if (f[i][j][k][l] != -1) return f[i][j][k][l];
        if (i == k && l == j) return f[i][j][k][l] = a[i][j];
        if (i == k) return f[i][j][k][l] = getH(j, l, i);
        if (j == l) return f[i][j][k][l] = getV(i, k, j);
        f[i][j][k][l] = MaxMin.Max(f[i][j][k][l], sol(i, j, i, l) + sol(i + 1, j, k, l));
        f[i][j][k][l] = MaxMin.Max(f[i][j][k][l], sol(k, j, k, l) + sol(i, j, k - 1, l));
        f[i][j][k][l] = MaxMin.Max(f[i][j][k][l], sol(i, j, k, j) + sol(i, j + 1, k, l));
        f[i][j][k][l] = MaxMin.Max(f[i][j][k][l], sol(i, l, k, l) + sol(i, j, k, l - 1));
        return f[i][j][k][l];
    }

    private int getV(int x1, int x2, int y) {
        int res = 0;
        for (int i = x1; i <= x2; i++) {
            res = res * 10 + a[i][y];
        }
        return res;
    }

    private int getH(int y1, int y2, int x) {
        int res = 0;
        for (int i = y1; i <= y2; i++) {
            res = res * 10 + a[x][i];
        }
        return res;
    }
}
