package Code;

import Lib.Algorithm.Math.MathAlgorithm;
import Lib.Algorithm.MaxMin;
import Utils.InputReader;
import Utils.OutputWriter;

import javax.swing.plaf.IconUIResource;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class DiceThrowing {
    private static final int MOD = (int) 1e9 + 7;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private InputReader in;
    private OutputWriter out;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        this.in = in;
        this.out = out;
        long[][] f = new long[25][150];
        f[1][1] = f[1][2] = f[1][3] = f[1][4] = f[1][5] = f[1][6] = 1;
        for (int i = 2; i <= 24; i++) {
            for (int j = 1; j < 150; j++) {
                for (int k = 1; k <= MaxMin.Min(6, j); k++) {
                    f[i][j] += f[i - 1][j - k];
                }
            }
        }
        while (true) {
            int n = in.nextInt();
            if (n == 0) return;
            int x = in.nextInt();
            long cur = 0;
            for (int i = 1; i < x; i++) {
                cur += f[n][i];
            }
            long tot = 1;
            for (int i = 1; i <= n; i++) tot *= 6;
            cur = tot - cur;

            if (cur == 0) {
                out.println(0);
                continue;
            }
            if (cur == tot) {
                out.println(1);
                continue;
            }
            long gcd = MathAlgorithm.gcd(tot,   cur);
            out.println(cur / gcd + "/" + tot / gcd);
        }
    }
}
