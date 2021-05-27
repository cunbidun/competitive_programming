package Code;


import FastIO.InputReader;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

@SuppressWarnings({"unused", "SpellCheckingInspection", "FieldCanBeLocal", "RedundantSuppression"})
public class PickUpSticks {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAXA = (int) 1e5 + 10;
    private static final int INF = (int) 2e9 + 7;
    private static final long INFLL = (long) 9e18 + 7;
    private static final double PI = 3.14159265358979323846264;
    private InputReader in;
    private PrintWriter out;
    private ArrayList<Integer>[] adjList;
    private ArrayList<Integer> ans;

    private boolean[] visited;
    private boolean[] done;
    private boolean f;


    public void solve(int testNumber, InputReader in, PrintWriter out) {
        this.in = in;
        this.out = out;
        while (true) {
            int n = in.nextInt();
            int m = in.nextInt();
            if (n == 0) return;
            visited = new boolean[n + 1];
            adjList = new ArrayList[n + 1];
            done = new boolean[n + 1];
            ans = new ArrayList<>();
            f = false;
            for (int i = 1; i <= n; i++) {
                adjList[i] = new ArrayList<>();
            }
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adjList[u].add(v);
            }
            for (int i = 1; i <= n; i++)
                if (!visited[i]) dfs(i);
            Collections.reverse(ans);
            if (f) out.println("IMPOSSIBLE");
            else for (int i : ans) out.println(i);
        }
    }

    private void dfs(int u) {
        visited[u] = true;
        for (int v : adjList[u]) {
            if (done[v]) continue;
            if (!visited[v]) dfs(v);
            else f = true;
        }
        done[u] = true;
        ans.add(u);
    }
}
