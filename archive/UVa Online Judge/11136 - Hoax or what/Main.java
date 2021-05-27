package Code;

import Lib.DataStructures.Tree.SBTree;
import FastIO.InputReader;

import java.io.PrintWriter;

@SuppressWarnings({"unused", "SpellCheckingInspection"})
public class HoaxOrWhat {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                int n = in.nextInt();
                if (n == 0) return;
                long ans = 0;
                SBTree<Integer> mSet = new SBTree<>(true);
                for (int i = 1; i <= n; i++) {
                    int num = in.nextInt();
                    for (int j = 1; j <= num; j++) {
                        mSet.add(in.nextInt());
                    }
                    ans += mSet.getMax() - mSet.getMin();
                    mSet.remove(mSet.getMax());
                    mSet.remove(mSet.getMin());
                }
                out.println(ans);
            }
        } catch (Exception ignored) {

        }
    }
}
