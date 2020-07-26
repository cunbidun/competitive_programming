package Code;

import java.util.ArrayList;

@SuppressWarnings("unused")
public class PerfectPermutation {
    ArrayList<Integer>[] graph;
    boolean[] vis;

    public int reorder(int[] P) {
        int ans = 0;
        int n = P.length;
        graph = new ArrayList[n];
        vis = new boolean[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph[i].add(P[i]);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        if (ans == 1) ans = 0;
        return ans;
    }

    private void dfs(int i) {
        vis[i] = true;
        for (int v : graph[i]) if (!vis[v]) dfs(v);
    }
}
