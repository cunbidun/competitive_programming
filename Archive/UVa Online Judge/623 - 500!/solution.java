package Code;

import Lib.DataStructures.BigInt;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection"})
public class Task {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                int n = in.nextInt();
                out.println(n + "!");
                BigInt num = new BigInt(1);
                for (int i = 1; i <= n; i++) num.mul(i);
                out.println(num);
            }
        } catch (Exception ignored) {
        }

    }
}
