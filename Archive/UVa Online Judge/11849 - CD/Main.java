package Code;

import Lib.DataStructures.Tree.SBTree;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection"})
public class CD {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                int n = in.nextInt();
                int m = in.nextInt();
                if (m == 0 && n == 0) return;
                SBTree<Integer> set = new SBTree<>(false);
                for (int i = 1; i <= n; i++) set.add(in.nextInt());
                int ans = 0;
                for (int i = 1; i <= m; i++) {
                    if (set.contains(in.nextInt())) ans++;
                }
                out.println(ans);
            }
        } catch (Exception ignored) {
        }
    }
}
