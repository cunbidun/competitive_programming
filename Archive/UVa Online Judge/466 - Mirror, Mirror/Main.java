package Code;

import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class MirrorMirror {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private InputReader in;
    private PrintWriter out;

    private int n;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
        try {
            int cnt = 0;
            while (true) {
                cnt++;
                n = in.nextInt();
                char[][] a = new char[n + 1][n + 1];
                char[][] b = new char[n + 1][n + 1];

                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= 2 * n; j++) {
                        char c = in.nextCharacter();
//                        out.print(c + " ");
                        if (j <= n) a[i][j] = c;
                        else b[i][j - n] = c;
                    }
//                    out.println();
                }
//                for (int i = 1; i <= n; i++) {
//                    for (int j = 1; j <= n; j++) {
//                        out.print(a[i][j] + " ");
//                    }
//                    out.println();
//                }

                if (isEqual(a, b)) {
                    out.println("Pattern " + cnt + " was preserved.");
                    continue;
                }

                char[][] tmp = R90(a);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was rotated 90 degrees.");
                    continue;
                }
                tmp = R90(tmp);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was rotated 180 degrees.");
                    continue;
                }
                tmp = R90(tmp);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was rotated 270 degrees.");
                    continue;
                }

                a = reflect(a);
                if (isEqual(a, b)) {
                    out.println("Pattern " + cnt + " was reflected vertically.");
                    continue;
                }
                tmp = R90(a);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was reflected vertically and rotated 90 degrees.");
                    continue;
                }
                tmp = R90(tmp);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was reflected vertically and rotated 180 degrees.");
                    continue;
                }
                tmp = R90(tmp);
                if (isEqual(tmp, b)) {
                    out.println("Pattern " + cnt + " was reflected vertically and rotated 270 degrees.");
                    continue;
                }
                out.println("Pattern " + cnt + " was improperly transformed.");
            }
        } catch (Exception irgnored) {
            return;
        }
    }

    private boolean isEqual(char[][] a, char[][] b) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    private char[][] R90(char[][] a) {
        char[][] res = new char[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[j][n - i + 1] = a[i][j];
            }
        }
        return res;
    }

    private char[][] reflect(char[][] a) {
        char[][] res = new char[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res[n - i + 1][j] = a[i][j];
            }
        }
        return res;
    }
}
