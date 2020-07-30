package Code;

import FastIO.InputReader;

import java.io.PrintWriter;
import java.text.DecimalFormat;

public class PowerOfCryptography {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                int n = in.nextInt();
                double p = in.nextDouble();
                DecimalFormat ft = new DecimalFormat("#");
                out.println(ft.format(Math.pow(Math.E, Math.log(p) / n)));
            }
        } catch (Exception ignored) {
        }
    }
}
