package Code;

import Lib.Algorithm.MaxMin;
import Lib.Algorithm.PrimeNumberAlgorithm;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;

@SuppressWarnings({"unused", "SpellCheckingInspection"})
public class PrimeFactors {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            PrimeNumberAlgorithm gen = new PrimeNumberAlgorithm(100000);
            while (true) {
                int n = in.nextInt();
                if (n == 0) return;
                boolean negative = false;
                if (n < 0) negative = true;
                ArrayList<Integer> a = gen.primeFactors(MaxMin.Max(n, -n));
                out.print(n + " = ");
                if (negative) out.print("-1 x ");
                for (int i = 0; i < a.size() - 1; i++) out.print(a.get(i) + " x ");
                out.println(a.get(a.size() - 1));
            }
        } catch (Exception ignored) {
        }
    }
}
