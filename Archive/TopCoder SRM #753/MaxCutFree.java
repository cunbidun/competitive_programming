package Code;

import java.util.ArrayList;

public class MaxCutFree {
    private ArrayList<Integer>[] adjList;
    private boolean[] vis;

    public int solve(int n, int[] a, int[] b) {
        adjList = new ArrayList[n];
        ArrayList<Integer>[] list = new ArrayList[n];
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < a.length; i++) {
            adjList[a[i]].add(b[i]);
            adjList[b[i]].add(a[i]);
        }
        int com = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
                com++;
            }
        }
        int ans = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < n; j++) vis[j] = false;
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (!vis[j]) {
                    dfs(j, a[i], b[i]);
                    cur++;
                }
            }
            if (cur != com) {
                ans++;
                list[a[i]].add(b[i]);
                list[b[i]].add(a[i]);
            }

        }

        int res = 0;
        while (ans > 0) {
            int pos = 0;
            int max = 0;
            for (int i = 0; i < n; i++) {
                if (list[i].size() == 1) {
                    res++;
                    pos = list[i].get(0);
                    ans -= list[pos].size();
                    list[pos].clear();
                    if (ans <= 0) break;
                    for (int j = 0; j < n; j++) list[j].remove((Integer) pos);
                }
            }

        }
        return n - res;
    }

    private void dfs(int u, int a, int b) {
        vis[u] = true;
        for (int v : adjList[u])
            if (!vis[v] && !(u == a && v == b) && !(u == b && v == a)) dfs(v, a, b);
    }

    private void dfs(int u) {
        vis[u] = true;
        for (int v : adjList[u]) if (!vis[v]) dfs(v);
    }

}
