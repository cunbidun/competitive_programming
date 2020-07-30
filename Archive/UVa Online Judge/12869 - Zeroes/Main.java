package Code;

import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class Zeroes {
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
        while (true) {
            long n = in.nextLong();
            long m = in.nextLong();
            if (n == 0 && m == 0) break;
            out.println(cal(m) - cal(n) + 1);
        }
//        out.println(cal(25));
    }

    private long cal(long x) {
        while (x % 5 != 0) x--;
        long num = 5;
        long res = 0;
//        while (num <= x) {
            res += (x - num) / num + 1;
//            num *= 5;
//        }
        return res;
    }
}
