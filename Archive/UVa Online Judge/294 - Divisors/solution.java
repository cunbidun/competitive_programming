package Code;

import Lib.Algorithm.Math.PrimeNumberAlgorithm;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class Divisors {
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
        int t = in.nextInt();
        PrimeNumberAlgorithm num = new PrimeNumberAlgorithm(100100);
        while (t-- > 0) {
            int l = in.nextInt();
            int r = in.nextInt();
            int ans = 0;
            int pos = INF;
            for (int i = l; i <= r; i++) {
                int tmp = num.numDivisors(i);
                if (tmp > ans) {
                    ans = tmp;
                    pos = i;
                }
            }
            out.println("Between " + l + " and " + r + ", " + pos + " has a maximum of " + ans + " divisors.");
        }
    }
}
