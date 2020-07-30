package Code;

import Lib.DataStructures.Tree.TreeList.TreeList;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.Arrays;

public class Jugs {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private int n, cA, cB;
    TreeList<String> cmd = new TreeList<>();
    private boolean[][] vis = new boolean[1010][1010];
    boolean done;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            while (true) {
                cA = in.nextInt();
                cB = in.nextInt();
                n = in.nextInt();
                cmd.clear();
                done = false;
                for (int i = 0; i <= 1000; i++) Arrays.fill(vis[i], false);
                vis[0][0] = true;
                cal(0, 0);
            }
        } catch (Exception ignored) {
        }
    }

    private void cal(int a, int b) {
        if (a == n || b == n) {
            done = true;
            for (String s : cmd) {
                System.out.println(s);
            }
            System.out.println("success");
            return;
        }

        if (done) return;
        if (a + b >= cB) {
            if (!vis[a + b - cB][cB]) {
                cmd.add("pour A B");
                vis[a + b - cB][cB] = true;
                cal(a + b - cB, cB);
                cmd.remove(cmd.size() - 1);
            }
        } else {
            if (!vis[0][b + a]) {
                cmd.add("pour A B");
                vis[0][b + a] = true;
                cal(0, b + a);
                cmd.remove(cmd.size() - 1);
            }
        }

        if (done) return;
        if (a + b >= cA) {
            if (!vis[cA][a + b - cA]) {
                cmd.add("pour B A");
                vis[cA][a + b - cA] = true;
                cal(cA, a + b - cA);
                cmd.remove(cmd.size() - 1);
            }
        } else {
            if (!vis[b + a][0]) {
                cmd.add("pour B A");
                vis[b + a][0] = true;
                cal(b + a, 0);
                cmd.remove(cmd.size() - 1);
            }
        }

        if (done) return;
        if (!vis[a][0]) {
            cmd.add("empty B");
            vis[a][0] = true;
            cal(a, 0);
            cmd.remove(cmd.size() - 1);
        }

        if (done) return;
        if (!vis[0][b]) {
            cmd.add("empty A");
            vis[0][b] = true;
            cal(0, b);
            cmd.remove(cmd.size() - 1);
        }

        if (done) return;
        if (!vis[cA][b]) {
            cmd.add("fill A");
            vis[cA][b] = true;
            cal(cA, b);
            cmd.remove(cmd.size() - 1);
        }

        if (done) return;
        if (!vis[a][cB]) {
            cmd.add("empty B");
            vis[a][cB] = true;
            cal(a, cB);
            cmd.remove(cmd.size() - 1);
        }
    }
}
