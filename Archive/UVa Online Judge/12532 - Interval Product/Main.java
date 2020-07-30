package Code;

import Lib.DataStructures.Tree.SegmentTree.STPointSetSum;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class IntervalProduct {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private InputReader in;
    private PrintWriter out;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
        try {
            while (true) {
                int n = in.nextInt();
                int m = in.nextInt();
                STPointSetSum zero = new STPointSetSum(n);
                STPointSetSum sign = new STPointSetSum(n);
                int[] a = in.nextIntArray(n, 1);
                for (int i = 1; i <= n; i++) {
                    int x = a[i];
                    if (x == 0) zero.set(i, 1);
                    if (x < 0) sign.set(i, 1);
                }
                while (m-- > 0) {
                    char cmd = in.nextCharacter();
                    if (cmd == 'C') {
                        int p = in.nextInt();
                        int v = in.nextInt();
                        if (v == 0) zero.set(p, 1);
                        else {
                            zero.set(p, 0);
                            if (v > 0) sign.set(p, 0);
                            else sign.set(p, 1);
                        }

                    } else {
                        int l = in.nextInt();
                        int r = in.nextInt();
                        if (zero.getSum(l, r) > 0) out.print(0);
                        else {
                            int tmp = sign.getSum(l, r);
                            if (tmp % 2 == 0) out.print('+');
                            else out.print('-');
                        }
                    }
                }
                out.println();
            }
        } catch (Exception ignored) {
        }
    }
}
