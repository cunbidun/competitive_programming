package Code;

import Lib.Algorithm.MaxMin;
import Lib.DataStructures.Tuple.TripIII;
import Lib.DataStructures.UnionFind;
import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

public class IsThereASecondWayLeft {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private int[] p, lvl;
    private ArrayList<Integer>[] adj;
    private int[][] con;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t = in.nextInt();
        for (int tt = 1; tt <= t; tt++) {
            ArrayList<TripIII> edge = new ArrayList<>();
            int n = in.nextInt();
            int m = in.nextInt();

            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                edge.add(new TripIII(w, u, v));
            }
            p = new int[n + 1];
            lvl = new int[n + 1];
            adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
            UnionFind dsu = new UnionFind(n);
            Collections.sort(edge);
            int MST = 0;
            con = new int[n + 1][n + 1];
            for (int i = 0; i < edge.size(); i++) {
                TripIII T = edge.get(i);
                int u = T.second;
                int v = T.third;
                if (!dsu.isSameSet(u, v)) {
                    con[u][v] = T.first;
                    con[v][u] = T.first;
                    adj[u].add(v);
                    adj[v].add(u);
                    MST += T.first;
                    dsu.mergeSet(u, v);
                    edge.remove(T);
                    i--;
                }
            }
            p[1] = 1;
            lvl[1] = 1;
            dfs(1, 1);
            out.print("Case #" + tt + " : ");
            if (dsu.getSize(dsu.findSet(1)) != n) {
                out.println("No way");
                continue;
            }
            if (m == n - 1) {
                out.println("No second way");
                continue;
            }
            int ans = INF;
            for (TripIII T : edge) {
                int u = T.second;
                int v = T.third;
                if(u == v) continue;
                ans = MaxMin.Min(ans, MST - findMax(u, v) + T.first);
            }
            out.println(ans);
        }
    }

    private void dfs(int u, int l) {
        for (int v : adj[u]) {
            if (v != l) {
                p[v] = u;
                lvl[v] = lvl[u] + 1;
                dfs(v, u);
            }
        }
    }

    private int findMax(int u, int v) {
        int max = 0;
        if (lvl[u] < lvl[v]) {
            int t = u;
            u = v;
            v = t;
        }
        while (lvl[u] > lvl[v]) {
            max = MaxMin.Max(max, con[u][p[u]]);
            u = p[u];
        }
        while (u != v) {
            max = MaxMin.Max(max, con[u][p[u]]);
            max = MaxMin.Max(max, con[v][p[v]]);
            u = p[u];
            v = p[v];
        }
        return max;
    }
}
